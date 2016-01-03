#ifndef QUARREL_INPUT_H
#define QUARREL_INPUT_H

#include <set>

namespace quarrel{

  /**
    * A class which represents the state of the keyboard of the machine
    * in particular, which keys are down.
    * TODO: Standardise the key ids between input APIs
    **/
  class keyboard{
  private:
    std::set<unsigned int> down_keys;
  public:
    keyboard();

    /**
      * Checks whether a key, from the given identifier is currently pressed
      * @param key the integer identifier of the key
      * @return true if the key is down
      **/
    bool is_key_down(unsigned int key) const;

    /**
      * Stores the fact that the given key is pressed
      * @param key the key that was pressed
      **/
    void key_pressed(unsigned int key);

    /**
      * Stores the fact that the given key is released
      * @param key the key that was released
      **/
    void key_released(unsigned int key);
  };

  class mouse{
  private:
    unsigned int num_buttons;
    std::set<unsigned int> down_buttons;
  public:
    mouse();

    /**
      * Checks whether a mouse button, from the given identifier is currently pressed
      * @param num the integer identifier of the mouse button
      * @return true if the mouse button is down
      **/
    bool is_button_down(unsigned int num) const;

    /**
      * Stores the fact that the given mouse button is pressed
      * @param num the mouse button that was pressed
      **/
    void button_pressed(unsigned int num);

    /**
      * Stores the fact that the given mouse button is released
      * @param num the mouse button that was released
      **/
    void button_released(unsigned int num);
  };
}

#endif
