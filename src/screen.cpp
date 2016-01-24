#include "screen.h"

quarrel::screen::screen(quarrel::color background_color) : background_color(background_color){

}

void quarrel::screen::add_entity(std::shared_ptr<quarrel::entity> entity){
  entities.push_back(entity);
}

void quarrel::screen::draw(quarrel::graphics& g) const{
  g.set_color(background_color);
  g.clear();
  for(std::shared_ptr<quarrel::entity> ent : entities){
    ent->draw(g);
  }
  g.swap_buffer();
}
