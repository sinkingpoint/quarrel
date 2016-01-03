#include "image.h"
#include <cstring>

quarrel::image::image(unsigned int width, unsigned int height) :
  width(width),
  height(height),
  pixels(new unsigned int[width * height]){
}

quarrel::image::image(unsigned int width, unsigned int height, unsigned int base_color) :
  width(width),
  height(height),
  pixels(new unsigned int[width * height]){

  for(unsigned int _x = 0;_x < width;_x ++){
    for(unsigned int _y = 0;_y < height;_y ++){
      pixels[_y * width + _x] = base_color;
    }
  }
}

quarrel::image::image(const quarrel::image& img) :
  width(img.width),
  height(img.height),
  pixels(new unsigned int[width * height]){

  std::memcpy(pixels.get(), img.pixels.get(), width * height);
}

quarrel::image::~image(){}

unsigned int quarrel::image::get_width() const{
  return width;
}

unsigned int quarrel::image::get_height() const{
  return height;
}

unsigned int quarrel::image::get_pixel(unsigned int x, unsigned int y){
  return pixels[y * width + x];
}

quarrel::image quarrel::image::get_subimage(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const{
  quarrel::image img(width, height);
  unsigned int* new_pixels = new unsigned int[width * height];
  for(unsigned int _x = 0;_x < width;_x ++){
    for(unsigned int _y = 0;_y < height;_y ++){
      new_pixels[y * width + x] = pixels[(y + _y) * this->width + (_x + x)];
    }
  }

  img.set_pixels(0, 0, width, height, new_pixels);
  delete[] new_pixels;
  return img;
}

void quarrel::image::set_pixel(unsigned int x, unsigned int y, unsigned int color){
  pixels[y * width + x] = color;
}

void quarrel::image::set_pixels(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int* pixels){
  for(unsigned int _x = 0;_x < width;_x ++){
    for(unsigned int _y = 0;_y < height;_y ++){
      pixels[(y + _y) * this->width + (_x + x)] = pixels[_y * width + _x];
    }
  }
}
