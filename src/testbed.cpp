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

  while(engine.is_running()){
    ent->move(1, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); //Return control back to the OS for stability
  }
}
