#include "imageio.h"
#include <png.h>

quarrel::image quarrel::load_image(const std::string& file_path){
  std::string extension = file_path.substr(file_path.find_last_of(".") + 1);
  if(extension == "png"){
    return quarrel::load_png_image(file_path);
  }
  else{
    throw std::runtime_error(std::string("Unsupported image type: ") + extension);
  }
}

quarrel::image quarrel::load_png_image(const std::string& file_path){
  FILE* fp = fopen(file_path.c_str(), "rb");
  if(!fp){
    throw std::runtime_error("Failed to open png file: ");
  }

  unsigned char header[8];
  fread(header, 1, 8, fp);
  if(png_sig_cmp(header, 0, 8)){
    fclose(fp);
    throw std::runtime_error("Invalid PNG file: ");
  }

  png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if(!png_ptr){
    fclose(fp);
    throw std::runtime_error("Failed to allocate read struct");
  }

  png_infop info_ptr = png_create_info_struct(png_ptr);
  if(!info_ptr){
    png_destroy_read_struct(&png_ptr, NULL, NULL);
    fclose(fp);
    throw std::runtime_error("Failed to allocate info struct");
  }

  png_set_sig_bytes(png_ptr, 8);

  if (setjmp(png_jmpbuf(png_ptr))) {
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
    fclose(fp);
    throw std::runtime_error("Failed to set jump");
  }

  png_init_io(png_ptr, fp);
  png_read_info(png_ptr, info_ptr);

  png_uint_32 width, height;
  int bit_depth, color_type, interlace_type;
  png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, &interlace_type, NULL, NULL);

  //Uniform the colour type (Make everything 8 bit RGB(A))
  if (color_type == PNG_COLOR_TYPE_PALETTE && bit_depth <= 8)png_set_expand(png_ptr);
  if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8) png_set_expand(png_ptr);
  if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)) png_set_expand(png_ptr);
  if (color_type == PNG_COLOR_TYPE_GRAY || color_type == PNG_COLOR_TYPE_GRAY_ALPHA)png_set_gray_to_rgb(png_ptr);

  //Strip 16 bit images down to 8 but
  if (bit_depth == 16)png_set_strip_16(png_ptr);

  //Expands any bit packing that happened
  if (bit_depth < 8)png_set_packing(png_ptr);

  //Handle interlacing
  unsigned int number_of_passes = png_set_interlace_handling(png_ptr);

  png_read_update_info(png_ptr, info_ptr);
  bit_depth = png_get_bit_depth(png_ptr, info_ptr);

  unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
  unsigned int num_channels = png_get_channels(png_ptr, info_ptr);

  png_bytep *row_pointers = new png_bytep[height];
  for(unsigned int y = 0;y < height;y ++){
    row_pointers[y] = new png_byte[row_bytes];
  }

  png_read_image(png_ptr, row_pointers);

  unsigned int *image_pixels = new unsigned int[width * height];
  for(unsigned int y = 0;y < height;y ++){
    for(unsigned int x = 0;x < width;x ++){
      png_byte x_byte = x * num_channels;
      png_byte r = row_pointers[y][x_byte];
      png_byte g = row_pointers[y][x_byte+1];
      png_byte b = row_pointers[y][x_byte+2];
      png_byte a;
      if(num_channels == 3){
        a = 0xFF;
      }
      else if(num_channels == 4){
        a = row_pointers[y][x_byte+3];
      }

      image_pixels[y * width + x] = ((int)a) << 24 | ((int)r) << 16 | ((int)g) << 8 | ((int)b);
    }
  }

  for(unsigned int y = 0;y < height;y ++){
    delete[] row_pointers[y];
  }
  delete[] row_pointers;

  fclose(fp);
  png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

  quarrel::image img = quarrel::image(width, height);
  img.set_pixels(0, 0, width, height, image_pixels);

  delete[] image_pixels;

  return img;
}
