#ifndef XDISPLAYHANDLER
#define XDISPLAYHANDLER

#include <X11/Xlib.h>

namespace quarrel{
  /**
    * This class implements an algorithm for arbitration of the X11
    * display object between the graphics thread and the event thread
    **/
  class xdisplayhandler{
  private:
    Display* disp;
    volatile int turn;
    volatile bool event_waiting, graphics_waiting;
  public:
    xdisplayhandler(Display* d);
    Display* event_lock();
    Display* graphics_lock();
    void event_unlock();
    void graphics_unlock();
  };
}

#endif
