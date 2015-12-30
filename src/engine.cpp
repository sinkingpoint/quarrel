#include "engine.h"
#include "xwindow.h"
#include <vector>
#include <memory>
#include "event.h"
#include <iostream>
#include <chrono>
#include <thread>

quarrel::engine::engine(std::string window_title, uint window_width, uint window_height) :
  game_window(new native_window(window_width, window_height))
{
  game_window->set_title(window_title);
}

quarrel::engine::~engine(){
  delete game_window;
  game_window = NULL;
}

bool quarrel::engine::is_running() const{
  return !game_window->is_closed();
}

void quarrel::engine::event_loop(void){
  std::vector<std::shared_ptr<quarrel::event>> events = game_window->get_eventhandler()->get_all_events();
  for(std::shared_ptr<quarrel::event> event : events){
    if(event->type == WindowClosedEvent){
      game_window->close();
    }
  }

  static int x = 0;
  x += 1;
  game_window->get_graphics()->fill_rectangle(x, 100, 50, 100);
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
