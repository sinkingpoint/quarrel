#ifndef QUARREL_GRAPHICS_H
#define QUARREL_GRAPHICS_H
#include <string>
#include "color.h"
#include "image.h"

namespace quarrel{
  class graphics{
  public:
    virtual void clear(void) = 0;

    virtual void set_color(unsigned int color) = 0;
    virtual void set_color(color color) = 0;
    virtual void fill_rectangle(int x, int y, unsigned int w, unsigned int h) = 0;
    virtual void draw_rectangle(int x, int y, unsigned int w, unsigned int h) = 0;

    virtual void fill_ellipse(int x, int y, unsigned int w, unsigned int h) = 0;
    virtual void draw_ellipse(int x, int y, unsigned int w, unsigned int h) = 0;

    virtual void draw_line(int x1, int y1, int x2, int y2) = 0;
    virtual void draw_string(int x, int y, std::string str) = 0;

    virtual void draw_arc(int x, int y, unsigned int width, unsigned int height, int angle1, int angle2) = 0;
    virtual void fill_arc(int x, int y, unsigned int width, unsigned int height, int angle1, int angle2) = 0;

    virtual void draw_image(int x, int y, image img) = 0;
  };
}

#endif
