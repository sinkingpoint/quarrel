#include "engine.h"
#include "xwindow.h"
#include "event.h"
#include "color.h"
#include "imageio.h"
#include <vector>
#include <memory>
#include <iostream>
#include <chrono>
#include <thread>

quarrel::engine::engine(std::string window_title, uint window_width, uint window_height) :
  game_window(new native_window(window_width, window_height))
{
  game_window->set_title(window_title);
  quarrel::color::black;
}

quarrel::engine::~engine(){
  delete game_window;
  game_window = NULL;
}

const quarrel::keyboard& quarrel::engine::get_keyboard() const{
  return keyboard_input;
}

const quarrel::mouse& quarrel::engine::get_mouse() const{
  return mouse_input;
}

bool quarrel::engine::is_running() const{
  return !game_window->is_closed();
}

void quarrel::engine::event_loop(void){
  std::vector<std::shared_ptr<quarrel::event>> events = game_window->get_eventhandler().get_all_events();
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

  if(keyboard_input.is_key_down(114)){
    x ++;
  }
  else if(keyboard_input.is_key_down(113)){
    x --;
  }

  game_window->get_graphics().clear();
  game_window->get_graphics().set_color(quarrel::color::blue);
  game_window->get_graphics().draw_rectangle(x, 100, 50, 100);
  game_window->get_graphics().draw_ellipse(x, 100, 50, 100);
  game_window->get_graphics().draw_line(x, 10, x+90, 100);
  game_window->get_graphics().draw_arc(x, 10, 90, 90, -45, 179);
  game_window->get_graphics().draw_string(x, 10, "Vimda Kali");

  static quarrel::image img = quarrel::load_image("testbed_assets/test_png.png");
  game_window->get_graphics().draw_image(50, 50, img);

  std::this_thread::sleep_for(std::chrono::milliseconds(1)); //Return control back to the OS for stability
}
