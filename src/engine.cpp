#include "engine.h"
#include "xwindow.h"
#include <vector>
#include <memory>
#include "event.h"
#include <iostream>

quarrel::engine::engine(std::string window_title, uint window_width, uint window_height) :
  game_window(new native_window(window_width, window_height))
{
  game_window->set_title(window_title);
}

quarrel::engine::~engine(){
  delete game_window;
}

bool quarrel::engine::is_running() const{
  return !game_window->is_closed();
}

void quarrel::engine::event_loop(void){
  std::vector<std::shared_ptr<quarrel::event>> events = game_window->get_eventhandler()->get_all_events();
  for(std::shared_ptr<quarrel::event> event : events){
    if(event->type == WindowClosedEvent){
      std::cout << "Closed!\n";
      game_window->close();
    }
  }
}
