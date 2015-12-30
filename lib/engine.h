#ifndef QUARREL_H
#define QUARREL_H
#define X_WINDOW_SYSTEM true

#include "helpers.h"
#include "window.h"
#include "input.h"
#include <string>

#ifdef X_WINDOW_SYSTEM
  #include "xwindow.h"
  typedef quarrel::xwindow native_window;
#endif

namespace quarrel{
  class engine{
  private:
    window* game_window;
    keyboard keyboard_input;
    mouse mouse_input;
  public:
    engine(std::string window_title, uint window_width, uint window_height);
    ~engine();

    const keyboard* get_keyboard() const;
    const mouse* get_mouse() const;

    void event_loop(void);
    bool is_running(void) const;
  };
}

#endif
