#include "engine.h"
#include "xwindow.h"

quarrel::engine::engine(std::string window_title, uint window_width, uint window_height) :
  game_window(new native_window(window_width, window_height))
{
  game_window->set_title(window_title);
}

quarrel::engine::~engine(){
  delete game_window;
}
