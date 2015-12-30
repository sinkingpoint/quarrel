#include <iostream>
#include "helpers.h"
#include "xwindow.h"
#include "graphics.h"

int main(int argc, char** args){
  UNUSED(argc);
  UNUSED(args);
  std::cout << "Cats\n";
  quarrel::xwindow window = quarrel::xwindow(640, 480);
  window.set_title("Quarrel Testbed");
  quarrel::graphics* gc = window.get_graphics();
  while(true){}
}
