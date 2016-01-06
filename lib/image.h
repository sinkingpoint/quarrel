#ifndef QUARREL_IMAGE_H
#define QUARREL_IMAGE_H

#include <memory>

namespace quarrel{
  /**
    * An abstract image class as a collection of pixel values with a width
    * and height
    **/
  class image{
  private:
    std::unique_ptr<unsigned int[]> pixels;
    unsigned int width;
    unsigned int height;
  public:
    /**
      * Constructs an empty image with size (width, height). Accessing the pixels
      * of this image is undefined behaviour until they are set
      * @param width the width of the image
      * @param height the height of the image
      **/
    image(unsigned int width, unsigned int height);

    /**
      * Constructs an image with all the pixels initialized to the same color
      * @param width the width of the image
      * @param height the height of the image
      * @param base_color The color that all the pixels are initialized to
      **/
    image(unsigned int width, unsigned int height, unsigned int base_color);

    image(const image& img);

    image(image&& img);

    ~image();

    /**
      * Returns the width of this image
      * @return the width of this image
      **/
    unsigned int get_width() const;

    /**
      * Returns the height of this image
      * @return the height of this image
      **/
    unsigned int get_height() const;

    /**
      * Gets a rectangular sub image of this image. The underlying pixel values
      * of the image are not shared so the returned image is safe to edit
      * @param x the left coordinate of the sub image to get, relative to the
      *          origin of the base image
      * @param y the top coordinate of the sub image to get, relative to the
      *          origin of the base image
      * @param width the width of the sub image to get
      * @param height the height of the sub image to get
      * @return an image of size (width, height) containing a copy of the
      *         pixels in the rectangle defined by (x, y), (width, height) in
      *         the parent (this) image
      ***/
    image get_subimage(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;

    /**
      * Gets the color of the pixel given by the coordinates (x, y)
      * @param x the x coordinate of the pixel to get
      * @param y the y coordinate of the pixel to get
      * @return An integer packed version of the color of the pixel at (x, y)
      **/
    unsigned int get_pixel(unsigned int x, unsigned int y);

    /**
      * Gets a copy of the pixels in this image inside the rectangle defined
      * @param x the left coordinate of the rectangle to get
      * @param y the top coordinate of the rectangle to get
      * @param width the width of the rectangle to get
      * @param height the height of the rectangle to get
      **/
    std::unique_ptr<unsigned int[]> get_pixels(unsigned int x, unsigned int y, unsigned int width, unsigned int height);

    /**
      * Sets the color of the pixel at (x, y)
      * @param x the x coordinate of the pixel to set
      * @param y the y coordinate of the pixel to set
      * @param color an integer packed version of the color to set the pixel to
      **/
    void set_pixel(unsigned int x, unsigned int y, unsigned int color);

    void set_pixels(unsigned int x, unsigned y, unsigned int width, unsigned int height, unsigned int* pixels);

    image& operator=(const image& img);
    image& operator=(image&& img);
  };
}

#endif
