#include "engine.h"
#include <memory>
#include <X11/Xlib.h>
#include <iostream>

int main(int argc, char** args){
  UNUSED(argc);
  UNUSED(args);
  quarrel::screen scr(quarrel::color::black);
  std::shared_ptr<quarrel::entity> ent = std::shared_ptr<quarrel::entity>(new quarrel::ellipse_entity(50, 50, 50, 50, quarrel::color::green));
  scr.add_entity(ent);
  quarrel::engine engine("Quarrel Testbed", 640, 480, scr);
  const quarrel::keyboard& keys = engine.get_keyboard();

  while(engine.is_running()){
    if(keys.is_key_down(113)){
      ent->move(-1, 0);
    }
    else if(keys.is_key_down(114)){
      ent->move(1, 0);
    }

    if(keys.is_key_down(111)){
      ent->move(0, -1);
    }
    else if(keys.is_key_down(116)){
      ent->move(0, 1);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); //Return control back to the OS for stability
  }
}
