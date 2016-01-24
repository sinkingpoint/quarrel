#include "xdisplayhandler.h"
#include <chrono>
#include <thread>

/**
  * This contains an implementation of Dekkers algorithm. There
  * are probably nicer ways to handle sharing the resource between two threads
  * but I could only remember this one off the top of my head.
  **/

quarrel::xdisplayhandler::xdisplayhandler(Display* disp) :
disp(disp),
turn(0),
event_waiting(false),
graphics_waiting(false){

}

Display* quarrel::xdisplayhandler::event_lock(){
  event_waiting = true;
  while(graphics_waiting){
    if(turn != 0){
      event_waiting = false;
      while(turn != 0){
          std::this_thread::sleep_for(std::chrono::milliseconds(10));
      }
      event_waiting = true;
    }
  }

  return disp;
}

Display* quarrel::xdisplayhandler::graphics_lock(){
  graphics_waiting = true;
  while(event_waiting){
    if(turn != 1){
      graphics_waiting = false;
      while(turn != 1){
          std::this_thread::sleep_for(std::chrono::milliseconds(10));
      }
      graphics_waiting = true;
    }
  }

  return disp;
}

void quarrel::xdisplayhandler::event_unlock(){
  turn = 1;
  event_waiting = false;
}

void quarrel::xdisplayhandler::graphics_unlock(){
  turn = 0;
  graphics_waiting = false;
}
