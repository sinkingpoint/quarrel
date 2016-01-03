#ifndef QUARREL_COLOR_H
#define QUARREL_COLOR_H

namespace quarrel{
  /**
    * A utility class to handle an RGB base color (However is
    * rather agnostic as to the actual storage format)
    */
  class color{
  private:
    const unsigned int base_color;
  public:
    /**
      * Constructs a color object from the given base color (Usually
      * an RGB integer, i.e. (r << 16 | g << 8 | b))
      * @param color The base color for this object
      */
    color(unsigned int color);

    /**
      * Constructs a color object from the given red, green and blue
      * values.
      * @param r The red component of this color
      * @param g The green component of this color
      * @param b The blue component of this color
      */
    color(unsigned char r, unsigned char g, unsigned char b);

    /**
      * Gets the red component of this color
      * @return The amount of red in this color
      */
    unsigned char get_red() const;

    /**
      * Gets the green component of this color
      * @return The amount of green in this color
      */
    unsigned char get_green() const;

    /**
      * Gets the blue component of this color
      * @return The amount of blue in this color
      */
    unsigned char get_blue() const;

    /**
      * Gets an integer packed version of this color
      * in the form (r << 16 | g << 8 | b)
      * @return the integer packed version of this color
      */
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
