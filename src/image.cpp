#include "image.h"
#include <algorithm>

quarrel::image::image(unsigned int _width, unsigned int _height) :
  width(_width),
  height(_height),
  pixels(new unsigned int[_width * _height]){
}

quarrel::image::image(unsigned int _width, unsigned int _height, unsigned int base_color) :
  width(_width),
  height(_height),
  pixels(new unsigned int[_width * _height]){

  for(unsigned int _x = 0;_x < _width;_x ++){
    for(unsigned int _y = 0;_y < _height;_y ++){
      pixels[_y * width + _x] = base_color;
    }
  }
}

quarrel::image::image(const quarrel::image& img) :
  width(img.width),
  height(img.height),
  pixels(new unsigned int[img.width * img.height]){

  std::copy(img.pixels.get(), img.pixels.get() + width * height, pixels.get());
}

quarrel::image::image(quarrel::image&& img) :
  width(img.width),
  height(img.height),
  pixels(std::move(img.pixels)){

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

std::unique_ptr<unsigned int[]> quarrel::image::get_pixels(unsigned int x, unsigned int y, unsigned int width, unsigned int height){
  std::unique_ptr<unsigned int[]> data(new unsigned int[width * height]);
  for(unsigned int _x = 0;x < width;x ++){
    for(unsigned int _y = 0;y < height;y ++){
      data[_y * width + _x] = pixels[(y + _y) * this->width + (_x + x)];
    }
  }

  return data;
}

void quarrel::image::set_pixel(unsigned int x, unsigned int y, unsigned int color){
  pixels[y * width + x] = color;
}

void quarrel::image::set_pixels(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int* pixels){
  for(unsigned int _x = 0;_x < width;_x ++){
    for(unsigned int _y = 0;_y < height;_y ++){
      this->pixels[(y + _y) * this->width + (_x + x)] = pixels[_y * width + _x];
    }
  }
}

quarrel::image& quarrel::image::operator=(const quarrel::image& img){
  if(width != img.width || height != img.height){
    width = img.width;
    height = img.height;
    pixels.reset(new unsigned int[width * height]);
  }

  std::copy(img.pixels.get(), img.pixels.get() + width * height, pixels.get());

  return *this;
}

quarrel::image& quarrel::image::operator=(quarrel::image&& img){
  width = img.width;
  height = img.height;
  pixels = std::move(img.pixels);
  return *this;
}
