#include "entity.h"

//Standard Entity
quarrel::entity::entity() : x(0), y(0){}
quarrel::entity::entity(int x, int y) : x(x), y(y){}

int quarrel::entity::get_x() const{
  return x;
}

int quarrel::entity::get_y() const{
  return y;
}

void quarrel::entity::set_position(int x, int y){
  this->x = x;
  this->y = y;
}

void quarrel::entity::move(int deltaX, int deltaY){
  this->x += deltaX;
  this->y += deltaY;
}

//Shape Entity
quarrel::shape_entity::shape_entity(unsigned int width, unsigned int height, quarrel::color col) :
entity(0, 0),
width(width),
height(height),
col(col){

}

quarrel::shape_entity::shape_entity(int x, int y, unsigned int width, unsigned int height, quarrel::color col) :
entity(x, y),
width(width),
height(height),
col(col){

}

unsigned int quarrel::shape_entity::get_width() const{
  return width;
}

unsigned int quarrel::shape_entity::get_height() const{
  return height;
}

quarrel::color quarrel::shape_entity::get_color() const{
  return col;
}

quarrel::rectangle_entity::rectangle_entity(unsigned int width, unsigned int height, quarrel::color col) :
shape_entity(width, height, col){

}

quarrel::rectangle_entity::rectangle_entity(int x, int y, unsigned int width, unsigned int height, quarrel::color col) :
shape_entity(x, y, width, height, col){

}

void quarrel::rectangle_entity::draw(quarrel::graphics& g) const{
  g.set_color(get_color());
  g.draw_rectangle(get_x(), get_y(), get_width(), get_height());
}

quarrel::filled_rectangle_entity::filled_rectangle_entity(unsigned int width, unsigned int height, quarrel::color col) :
shape_entity(width, height, col){

}

quarrel::filled_rectangle_entity::filled_rectangle_entity(int x, int y, unsigned int width, unsigned int height, quarrel::color col) :
shape_entity(x, y, width, height, col){

}

void quarrel::filled_rectangle_entity::draw(quarrel::graphics& g) const{
  g.set_color(get_color());
  g.fill_rectangle(get_x(), get_y(), get_width(), get_height());
}

quarrel::ellipse_entity::ellipse_entity(unsigned int width, unsigned int height, quarrel::color col) :
shape_entity(width, height, col){

}

quarrel::ellipse_entity::ellipse_entity(int x, int y, unsigned int width, unsigned int height, quarrel::color col) :
shape_entity(x, y, width, height, col){

}

void quarrel::ellipse_entity::draw(quarrel::graphics& g) const{
  g.set_color(get_color());
  g.draw_ellipse(get_x(), get_y(), get_width(), get_height());
}

quarrel::filled_ellipse_entity::filled_ellipse_entity(unsigned int width, unsigned int height, quarrel::color col) :
shape_entity(width, height, col){

}

quarrel::filled_ellipse_entity::filled_ellipse_entity(int x, int y, unsigned int width, unsigned int height, quarrel::color col) :
shape_entity(x, y, width, height, col){

}

void quarrel::filled_ellipse_entity::draw(quarrel::graphics& g) const{
  g.set_color(get_color());
  g.fill_ellipse(get_x(), get_y(), get_width(), get_height());
}

//Image entity
quarrel::image_entity::image_entity(quarrel::image img) : entity(0, 0), img(img){}
quarrel::image_entity::image_entity(int x, int y, quarrel::image img) : entity(x, y), img(img){}

void quarrel::image_entity::draw(quarrel::graphics& g) const{
  g.draw_image(x, y, img);
}
