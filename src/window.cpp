#include "window.h"

quarrel::window::window() : closed(false){

}

bool quarrel::window::is_closed() const{
  return closed;
}
