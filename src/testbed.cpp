#include <iostream>
#include "helpers.h"
#include "xwindow.h"

int main(int argc, char** args){
  UNUSED(argc);
  UNUSED(args);
  std::cout << "Cats\n";
  quarrel::xwindow window = quarrel::xwindow(640, 480);
  while(true){}
}
