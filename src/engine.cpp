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
      return;
    }
    else if(event->type == MousePressedEvent){
      std::shared_ptr<quarrel::mouse_pressed_event> ev = std::static_pointer_cast<quarrel::mouse_pressed_event>(event);
      mouse_input.button_pressed(ev->button);
    }
    else if(event->type == MouseReleasedEvent){
      std::shared_ptr<quarrel::mouse_released_event> ev = std::static_pointer_cast<quarrel::mouse_released_event>(event);
      mouse_input.button_released(ev->button);
    }
    else if(event->type == KeyPressedEvent){
      std::shared_ptr<quarrel::key_pressed_event> ev = std::static_pointer_cast<quarrel::key_pressed_event>(event);
      keyboard_input.key_pressed(ev->key);
    }
    else if(event->type == KeyReleasedEvent){
      std::shared_ptr<quarrel::key_released_event> ev = std::static_pointer_cast<quarrel::key_released_event>(event);
      keyboard_input.key_released(ev->key);
    }
  }

  static int x = 100;

  if(keyboard_input.is_key_down(36)){
    x ++;
  }
  
  game_window->get_graphics()->set_color(0x0000FF);
  game_window->get_graphics()->draw_rectangle(x, 100, 50, 100);
  game_window->get_graphics()->draw_ellipse(x, 100, 50, 100);
  game_window->get_graphics()->draw_line(10, 10, 100, 100);
  game_window->get_graphics()->draw_arc(10, 10, 90, 90, -45, 180);
  game_window->get_graphics()->draw_string(10, 10, "Vimda Kali");
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
