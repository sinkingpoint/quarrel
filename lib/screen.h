#ifndef QUARREL_SCREEN_H
#define QUARREL_SCREEN_H

#include <vector>
#include <memory>
#include "entity.h"
#include "color.h"

namespace quarrel{
  class screen{
  private:
    std::vector<std::shared_ptr<entity>> entities;
    color background_color;
  public:
    screen(color background_color);
    void add_entity(std::shared_ptr<entity> e);
    void draw(graphics& g) const;
  };
}

#endif
