#ifndef QUARREL_WINDOW_H
#define QUARREL_WINDOW_H

#include <string>
#include "helpers.h"
#include "graphics.h"
#include "eventhandler.h"

namespace quarrel{
  class window{
  private:
  protected:
    bool closed;
  public:
    window();

    bool is_closed() const;

    virtual void close() = 0;
    virtual void set_size(uint width, uint height) = 0;
    virtual void set_title(std::string title) = 0;
    virtual graphics* get_graphics(void) = 0;
    virtual eventhandler* get_eventhandler(void) = 0;
  };
}

#endif
