#ifndef QUARREL_SCREEN_H
#define QUARREL_SCREEN_H

#include <vector>
#include <memory>
#include "entity.h"

namespace quarrel{
  class screen{
  private:
    std::vector<std::shared_ptr<entity>> entities;
  public:
    screen();
    void add_entity(std::shared_ptr<entity> e);
    void draw(graphics& g) const;
  };
}

#endif
