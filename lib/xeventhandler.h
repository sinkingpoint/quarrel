#ifndef QUARREL_X_EVENT_HANDLER
#define QUARREL_X_EVENT_HANDLER

#include "eventhandler.h"
#include "event.h"
#include <X11/Xlib.h>

namespace quarrel{
  class xeventhandler : public eventhandler{
  private:
    XEvent e;
    Display* display;
  public:
    xeventhandler(Display* display);
    virtual std::vector<std::shared_ptr<event>> get_all_events(void);
  };
}

#endif
