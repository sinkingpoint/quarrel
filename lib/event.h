#ifndef QUARREL_EVENT_H
#define QUARREL_EVENT_H

#define MousePressedEvent 1
#define MouseReleasedEvent 2
#define KeyPressedEvent 3
#define KeyReleasedEvent 4
#define WindowClosedEvent 5

namespace quarrel{
  class event{
  public:
    unsigned int type;
    event(unsigned int type);
  };

  class mouse_pressed_event : public event{
  public:
    mouse_pressed_event();
    unsigned int button;
  };

  class mouse_released_event : public event{
  public:
    mouse_released_event();
    unsigned int button;
  };

  class key_pressed_event : public event{
  public:
    key_pressed_event();
    char key_char;
  };

  class key_released_event : public event{
  public:
    key_released_event();
    char key_char;
  };

  class window_closed_event : public event{
  public:
    window_closed_event();
  };
}

#endif
