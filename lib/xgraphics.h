#ifndef QUARREL_XGRAPHICS_H
#define QUARREL_XGRAPHICS_H

#include "graphics.h"
#include <X11/Xlib.h>

namespace quarrel{
  class xgraphics : public graphics{
  private:
    GC context;
    Window window;
    Display* display;
  public:
    xgraphics(Display* display, Window window);
    virtual void fill_rectangle(int x, int y, uint w, uint h);
  };
}

#endif
