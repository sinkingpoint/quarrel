#ifndef QUARREL_COLOR_H
#define QUARREL_COLOR_H

namespace quarrel{
  class color{
  private:
    const unsigned int base_color;
  public:
    color(unsigned int color);
    color(unsigned char r, unsigned char g, unsigned char b);

    unsigned char get_red() const;
    unsigned char get_green() const;
    unsigned char get_blue() const;
    unsigned int get() const;

    //Some basic colors
    static const quarrel::color black;

    static const quarrel::color red;
    static const quarrel::color green;
    static const quarrel::color blue;

    static const quarrel::color pink;
    static const quarrel::color yellow;
    static const quarrel::color turquoise;

    static const quarrel::color white;
  };
}

#endif
