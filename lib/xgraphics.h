#ifndef QUARREL_XGRAPHICS_H
#define QUARREL_XGRAPHICS_H

#include "graphics.h"
#include <X11/Xlib.h>
#include <string>

namespace quarrel{
  class xgraphics : public graphics{
  private:
    GC context;
    Window window;
    Display* display;
  public:
    xgraphics(Display* display, Window window);

    virtual void clear(void);

    virtual void set_color(unsigned int color);

    virtual void fill_rectangle(int x, int y, unsigned int w, unsigned int h);
    virtual void draw_rectangle(int x, int y, unsigned int w, unsigned int h);

    virtual void fill_ellipse(int x, int y, unsigned int w, unsigned int h);
    virtual void draw_ellipse(int x, int y, unsigned int w, unsigned int h);

    virtual void draw_line(int x1, int y1, int x2, int y2);
    virtual void draw_string(int x, int y, std::string str);

    virtual void draw_arc(int x, int y, unsigned int width, unsigned int height, int angle1, int angle2);
    virtual void fill_arc(int x, int y, unsigned int width, unsigned int height, int angle1, int angle2);

  };
}

#endif
