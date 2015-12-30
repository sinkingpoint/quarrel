#ifndef QUARREL_GRAPHICS_H
#define QUARREL_GRAPHICS_H

namespace quarrel{
  class graphics{
  public:
    virtual void fill_rectangle(int x, int y, unsigned int w, unsigned int h) = 0;
  };
}

#endif
