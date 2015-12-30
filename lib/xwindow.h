#ifndef QUARREL_X_WINDOW_H
#define QUARREL_X_WINDOW_H

#include <iostream>
#include <X11/Xlib.h>
#include "window.h"
#include "graphics.h"
#include "xgraphics.h"

namespace quarrel{
  class xwindow : window{
  private:
    Display* display;
    Window base_window;
    xgraphics graphics_context;
  public:
    xwindow(uint width, uint height);
    ~xwindow();
    virtual graphics* get_graphics(void);
    virtual void set_size(uint width, uint height);
    virtual void set_title(std::string title);
  };
}

#endif
