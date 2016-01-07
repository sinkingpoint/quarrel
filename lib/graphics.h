#ifndef QUARREL_GRAPHICS_H
#define QUARREL_GRAPHICS_H
#include <string>
#include "color.h"
#include "image.h"

namespace quarrel{
  /**
    * An abstract graphics interface with methods for drawing various
    * things
    **/
  class graphics{
  public:
    /**
      * Clears the graphics object, resetting it back to some background color
      **/
    virtual void clear(void) = 0;

    /**
      * Sets the colour this graphics object draws in
      * @param color an integer packed RGB interpretation of the color
      **/
    virtual void set_color(unsigned int color) = 0;

    /**
      * Sets the colour this graphics object draws in
      * @param color A quarrel::color interpretation of the color
      **/
    virtual void set_color(color color) = 0;

    /**
      * Fills a rectangular area with top-left corner (x, y) with width w
      * and height h
      * @param x the left coordinate of the rectangle to fill
      * @param y the top coordinate of the rectangle to fill
      * @param w the width of the rectangle to fill
      * @param h the height of the rectangle to fill
      **/
    virtual void fill_rectangle(int x, int y, unsigned int w, unsigned int h) = 0;

    /**
      * Draws the outline of a rectangular area with top-left corner (x, y)
      * with width w and height h
      * @param x the left coordinate of the rectangle to draw
      * @param y the top coordinate of the rectangle to draw
      * @param w the width of the rectangle to draw
      * @param h the height of the rectangle to draw
      **/
    virtual void draw_rectangle(int x, int y, unsigned int w, unsigned int h) = 0;

    /**
      * Fills an elliptical area defined with the top left coordinates of (x, y)
      * with width w and height h
      * @param x the left coordinate of the ellipse to fill
      * @param y the top coordinate of the ellipse to fill
      * @param w the width of the ellipse to fill
      * @param h the height of the ellipse to fill
      **/
    virtual void fill_ellipse(int x, int y, unsigned int w, unsigned int h) = 0;

    /**
      * Draws an elliptical area defined with the top left coordinates of (x, y)
      * with width w and height h
      * @param x the left coordinate of the ellipse to draw
      * @param y the top coordinate of the ellipse to draw
      * @param w the width of the ellipse to draw
      * @param h the height of the ellipse to draw
      **/
    virtual void draw_ellipse(int x, int y, unsigned int w, unsigned int h) = 0;

    /**
      * Draws a straight line from (x1, y1) to (x2, y2)
      * @param x1 the x coordinate of the starting point of the linev
      * @param y1 the y coordinate of the starting point of the line
      * @param x2 the x coordinate of the end point of the line
      * @param y2 the y coordinate of the end point of the line
      **/
    virtual void draw_line(int x1, int y1, int x2, int y2) = 0;

    /**
      * Draws a string of text with top-left coordinates (x, y)
      * @param x the left of the string
      * @param y the top of the string
      * @param str the string to draw
      **/
    virtual void draw_string(int x, int y, std::string str) = 0;

    virtual void swap_buffer() = 0;

    /**
      * Draws an arc with top left coordinates at (x, y), with major and
      * minor axes (width, height).
      * @param x The left coordinate of the arc
      * @param y The top coordinate of the arc
      * @param width the width of the arc
      * @param height the top of the arc
      * @param angle1 The starting angle of the arc, in degrees, relative
      *               to the 3 o'clock position from the center
      * @param angle2 The finishing angle of the arc, in degrees, relative
      *               to the 3 o'clock position from the center
      **/
    virtual void draw_arc(int x, int y, unsigned int width, unsigned int height, int angle1, int angle2) = 0;

    /**
      * Fills an arc with top left coordinates at (x, y), with major and
      * minor axes (width, height).
      * @param x The left coordinate of the arc
      * @param y The top coordinate of the arc
      * @param width the width of the arc
      * @param height the top of the arc
      * @param angle1 The starting angle of the arc, in degrees, relative
      *               to the 3 o'clock position from the center
      * @param angle2 The finishing angle of the arc, in degrees, relative
      *               to the 3 o'clock position from the center
      **/
    virtual void fill_arc(int x, int y, unsigned int width, unsigned int height, int angle1, int angle2) = 0;

    /**
      * Draws a loaded image to the graphics pane. May cache the image with
      * some native implementation
      * @param x The left coordinate of the image
      * @param y The top coordinate of the image
      * @param img The image to draw
      **/
    virtual void draw_image(int x, int y, image img) = 0;
  };
}

#endif
