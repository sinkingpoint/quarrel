#ifndef QUARREL_INPUT_H
#define QUARREL_INPUT_H

#include <set>

namespace quarrel{
  class keyboard{
  private:
    std::set<unsigned int> down_keys;
  public:
    keyboard();
    bool is_key_down(unsigned int key) const;
    void key_pressed(unsigned int key);
    void key_released(unsigned int key);
  };

  class mouse{
  private:
    unsigned int num_buttons;
    std::set<unsigned int> down_buttons;
  public:
    mouse();
    bool is_button_down(unsigned int num) const;
    void button_pressed(unsigned int num);
    void button_released(unsigned int num);
  };
}

#endif
