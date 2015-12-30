#include "input.h"
#include <iostream>

quarrel::keyboard::keyboard(){

}

bool quarrel::keyboard::is_key_down(unsigned int key) const{
  return down_keys.find(key) != down_keys.end();
}

void quarrel::keyboard::key_pressed(unsigned int key){
  down_keys.insert(key);
  std::cout << "Key(" << key << ") pressed\n";
}

void quarrel::keyboard::key_released(unsigned int key){
  if(is_key_down(key)){
    down_keys.erase(down_keys.find(key));
  }
}

quarrel::mouse::mouse(){

}

bool quarrel::mouse::is_button_down(unsigned int key) const{
  return down_buttons.find(key) != down_buttons.end();
}

void quarrel::mouse::button_pressed(unsigned int key){
  down_buttons.insert(key);
}

void quarrel::mouse::button_released(unsigned int key){
  down_buttons.erase(down_buttons.find(key));
}
