#ifndef QUARREL_ENTITY_H
#define QUARREL_ENTITY_H

#include "image.h"
#include "graphics.h"

namespace quarrel{
  class entity{
  protected:
    int x, y;
  public:
    entity();
    entity(int x, int y);

    void set_position(int x, int y);
    void move(int deltaX, int deltaY);

    virtual void draw(graphics& g) = 0;
  };

  class image_entity : public entity{
  private:
    image img;
  public:
    image_entity(image img);
    image_entity(int x, int y, image img);
    void draw(graphics& g) const;
  };
}

#endif
