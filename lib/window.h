#ifndef QUARREL_WINDOW_H
#define QUARREL_WINDOW_H

#include <string>
#include "helpers.h"

namespace quarrel{
  class window{
  private:
  public:
    virtual void set_size(uint width, uint height) = 0;
    virtual void set_title(std::string title) = 0;
  };
}

#endif
