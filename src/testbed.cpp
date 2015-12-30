#include <iostream>
#include "engine.h"

int main(int argc, char** args){
  UNUSED(argc);
  UNUSED(args);
  quarrel::engine engine("Quarrel Testbed", 640, 480);
  while(engine.is_running()){
    engine.event_loop();
  }
}
