#ifndef QUARREL_IMAGEIO_H
#define QUARREL_IMAGEIO_H

#include "image.h"
#include <string>

namespace quarrel{
  quarrel::image load_image(const std::string& file_path);
  quarrel::image load_png_image(const std::string& file_path);
}

#endif
