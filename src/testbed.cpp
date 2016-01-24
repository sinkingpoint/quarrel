#include <iostream>
#include "engine.h"

int main(int argc, char** args){
  UNUSED(argc);
  UNUSED(args);

  quarrel::screen scr(quarrel::color::blue);

  quarrel::engine engine("Quarrel Testbed", 640, 480, scr);
  while(engine.is_running()){
    engine.event_loop();
  }
}
