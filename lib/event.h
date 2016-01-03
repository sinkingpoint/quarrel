#ifndef QUARREL_EVENT_H
#define QUARREL_EVENT_H

#define MousePressedEvent 1
#define MouseReleasedEvent 2
#define KeyPressedEvent 3
#define KeyReleasedEvent 4
#define WindowClosedEvent 5

namespace quarrel{

  /**
    * The base event class from which all events inherit. Only has an
    * identifier for the type of event
    **/
  class event{
  public:
    unsigned int type;
    event(unsigned int type);
  };

  /**
    * A mouse pressed event, created when a mouse button is pressed.
    */
  class mouse_pressed_event : public event{
  public:
    mouse_pressed_event(unsigned int button);
    const unsigned int button;
  };

  /**
    * A mouse released event, created when a mouse button is released.
    */
  class mouse_released_event : public event{
  public:
    mouse_released_event(unsigned int button);
    const unsigned int button;
  };

  /**
    * A key pressed event, created when a key on the keyboard is pressed
    **/
  class key_pressed_event : public event{
  public:
    key_pressed_event(unsigned int key);
    const unsigned int key;
  };

  /**
    * A key released event, created when a key on the keyboard is released
    **/
  class key_released_event : public event{
  public:
    key_released_event(unsigned int key);
    const unsigned int key;
  };

  /**
    * A window closed event, created when the main game window is closed 
    **/
  class window_closed_event : public event{
  public:
    window_closed_event();
  };
}

#endif
