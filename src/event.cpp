#include "event.h"

quarrel::event::event(unsigned int type) : type(type){

}

quarrel::mouse_pressed_event::mouse_pressed_event(unsigned int button) : event(MousePressedEvent), button(button){

}

quarrel::mouse_released_event::mouse_released_event(unsigned int button) : event(MouseReleasedEvent), button(button){

}

quarrel::key_pressed_event::key_pressed_event(unsigned int key) : event(KeyPressedEvent), key(key){

}

quarrel::key_released_event::key_released_event(unsigned int key) : event(KeyReleasedEvent), key(key){

}

quarrel::window_closed_event::window_closed_event() : event(WindowClosedEvent){

}
