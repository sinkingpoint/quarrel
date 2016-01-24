#include "screen.h"

quarrel::screen::screen(){}

void quarrel::screen::add_entity(std::shared_ptr<quarrel::entity> entity){
  entities.push_back(entity);
}

void quarrel::screen::draw(quarrel::graphics& g) const{
  for(std::shared_ptr<quarrel::entity> ent : entities){
    ent->draw(g);
  }
}
