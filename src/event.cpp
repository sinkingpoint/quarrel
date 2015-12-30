#include "event.h"

quarrel::event::event(unsigned int type) : type(type){

}

quarrel::mouse_pressed_event::mouse_pressed_event(unsigned int button) : button(button), event(MousePressedEvent){

}

quarrel::mouse_released_event::mouse_released_event(unsigned int button) : button(button), event(MouseReleasedEvent){

}

quarrel::key_pressed_event::key_pressed_event(unsigned int key) : key(key), event(KeyPressedEvent){

}

quarrel::key_released_event::key_released_event(unsigned int key) : key(key), event(KeyReleasedEvent){

}

quarrel::window_closed_event::window_closed_event() : event(WindowClosedEvent){

}
