#include "image.h"

quarrel::image::image(unsigned int width, unsigned int height) :
  width(width),
  height(height),
  pixels(new unsigned int[width * height]){
}

quarrel::image::~image(){
  delete[] pixels;
  pixels = nullptr;
}

unsigned int quarrel::image::get_width() const{
  return width;
}

unsigned int quarrel::image::get_height() const{
  return height;
}

quarrel::image quarrel::image::get_subimage(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const{
  quarrel::image img(width, height);
  unsigned int* pixels = new unsigned int[width * height];
  for(unsigned int _x = 0;_x < width;_x ++){
    for(unsigned int _y = 0;_y < height;_y ++){
      pixels[y * width + x] = pixels[(y + _y) * this->width + (_x + x)];
    }
  }

  img.set_pixels(0, 0, width, height, pixels);
  delete[] pixels;
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
