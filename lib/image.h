#ifndef QUARREL_IMAGE_H
#define QUARREL_IMAGE_H

namespace quarrel{
  class image{
  private:
    unsigned int* pixels;
    unsigned int width;
    unsigned int height;
  public:
    image(unsigned int width, unsigned int height);
    ~image();

    unsigned int get_width() const;
    unsigned int get_height() const;
    image get_subimage(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;

    void set_pixel(unsigned int x, unsigned int y, unsigned int color);
    void set_pixels(unsigned int x, unsigned y, unsigned int width, unsigned int height, unsigned int* pixels);
  };
}

#endif
