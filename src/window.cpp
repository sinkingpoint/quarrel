#include "window.h"

quarrel::window::window() : closed(false){

}

quarrel::window::~window(){

}

bool quarrel::window::is_closed() const{
  return closed;
}
