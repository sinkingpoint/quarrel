#ifndef QUARREL_ENTITY_H
#define QUARREL_ENTITY_H

#include "image.h"
#include "graphics.h"
#include "color.h"

namespace quarrel{
  class entity{
  protected:
    int x, y;
  public:
    entity();
    entity(int x, int y);

    void set_position(int x, int y);
    void move(int deltaX, int deltaY);

    int get_x() const;
    int get_y() const;

    virtual void draw(graphics& g) const = 0;
  };

  class shape_entity : public entity{
  private:
    unsigned int width, height;
    color col;
  public:
    shape_entity(unsigned int width, unsigned int height, color col);
    shape_entity(int x, int y, unsigned int width, unsigned int height, color col);

    unsigned int get_width() const;
    unsigned int get_height() const;
    color get_color() const;

    virtual void draw(graphics& g) const = 0;
  };

  class rectangle_entity : public shape_entity{
  public:
    rectangle_entity(unsigned int width, unsigned int height, color col);
    rectangle_entity(int x, int y, unsigned int width, unsigned int height, color col);
    void draw(graphics& g) const;
  };

  class filled_rectangle_entity : public shape_entity{
  public:
    filled_rectangle_entity(unsigned int width, unsigned int height, color col);
    filled_rectangle_entity(int x, int y, unsigned int width, unsigned int height, color col);
    void draw(graphics& g) const;
  };

  class ellipse_entity : public shape_entity{
  public:
    ellipse_entity(unsigned int width, unsigned int height, color col);
    ellipse_entity(int x, int y, unsigned int width, unsigned int height, color col);
    void draw(graphics& g) const;
  };

  class filled_ellipse_entity : public shape_entity{
  public:
    filled_ellipse_entity(unsigned int width, unsigned int height, color col);
    filled_ellipse_entity(int x, int y, unsigned int width, unsigned int height, color col);
    void draw(graphics& g) const;
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
