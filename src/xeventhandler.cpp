#include "xeventhandler.h"
#include "event.h"
#include <vector>
#include <memory>

quarrel::xeventhandler::xeventhandler(Display* display) :
  display(display){
}

std::vector<std::shared_ptr<quarrel::event>> quarrel::xeventhandler::get_all_events(void){
  std::vector<std::shared_ptr<event>> events;
  while(XPending(display) > 0){
    XNextEvent(display, &e);
    if(e.type == KeyPress){
      events.push_back(std::shared_ptr<quarrel::event>(new quarrel::key_pressed_event(e.xkey.keycode)));
    }
    else if(e.type == KeyRelease){
      events.push_back(std::shared_ptr<quarrel::event>(new quarrel::key_released_event(e.xkey.keycode)));
    }
    else if(e.type == ButtonPress){
      events.push_back(std::shared_ptr<quarrel::event>(new quarrel::mouse_pressed_event(e.xbutton.button)));
    }
    else if(e.type == ButtonRelease){
      events.push_back(std::shared_ptr<quarrel::event>(new quarrel::mouse_released_event(e.xbutton.button)));
    }
    else if(e.type == ClientMessage){
      events.push_back(std::shared_ptr<quarrel::event>(new quarrel::window_closed_event()));
    }
  }

  return events;
}
