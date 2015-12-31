#include "color.h"

quarrel::color::color(unsigned int color) : base_color(color){

}

quarrel::color::color(unsigned char r, unsigned char g, unsigned char b) : base_color(r << 16 | g << 8 | b){

}

unsigned char quarrel::color::get_red() const{
  return (base_color >> 16) & 0xFF;
}

unsigned char quarrel::color::get_green() const{
  return (base_color >> 8) & 0xFF;
}

unsigned char quarrel::color::get_blue() const{
  return base_color & 0xFF;
}

unsigned int quarrel::color::get() const{
  return base_color;
}

const quarrel::color quarrel::color::black = quarrel::color(0x0);

const quarrel::color quarrel::color::red = quarrel::color(255, 0, 0);
const quarrel::color quarrel::color::green = quarrel::color(0, 255, 0);
const quarrel::color quarrel::color::blue = quarrel::color(0, 0, 255);

const quarrel::color quarrel::color::pink = quarrel::color(255, 0, 255);
const quarrel::color quarrel::color::yellow = quarrel::color(255, 255, 0);
const quarrel::color quarrel::color::turquoise = quarrel::color(0, 255, 255);

const quarrel::color quarrel::color::white = quarrel::color(255, 255, 255);
