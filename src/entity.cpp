#include "entity.h"

quarrel::entity::entity() : x(0), y(0){}

quarrel::entity::entity(int x, int y) : x(x), y(y){}

void quarrel::entity::set_position(int x, int y){
  this->x = x;
  this->y = y;
}

void quarrel::entity::move(int deltaX, int deltaY){
  this->x += deltaX;
  this->y += deltaY;
}

//Image entity
quarrel::image_entity::image_entity(quarrel::image img) : entity(0, 0), img(img){}
quarrel::image_entity::image_entity(int x, int y, quarrel::image img) : entity(x, y), img(img){}

void quarrel::image_entity::draw(quarrel::graphics& g){
  g.draw_image(x, y, img);
}
