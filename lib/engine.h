#ifndef QUARREL_H
#define QUARREL_H
#define X_WINDOW_SYSTEM true

#include "helpers.h"
#include "window.h"
#include <string>

#ifdef X_WINDOW_SYSTEM
  #include "xwindow.h"
  typedef quarrel::xwindow native_window;
#endif

namespace quarrel{
  class engine{
  private:
    window* game_window;
  public:
    engine(std::string window_title, uint window_width, uint window_height);
    ~engine();
    void event_loop(void);

    bool is_running(void) const;
  };
}

#endif
