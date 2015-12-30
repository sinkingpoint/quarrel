#ifndef QUARREL_X_WINDOW_H
#define QUARREL_X_WINDOW_H

#include <iostream>
#include <X11/Xlib.h>
#include "window.h"

namespace quarrel{
  class xwindow : window{
  private:
    Display* display;
    Window baseWindow;
  public:
    xwindow(uint width, uint height);
    ~xwindow();
    virtual void set_size(uint width, uint height);
    virtual void set_title(std::string title);
  };
}

#endif
