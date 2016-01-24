#ifndef QUARREL_H
#define QUARREL_H
#define X_WINDOW_SYSTEM true

#include "helpers.h"
#include "window.h"
#include "input.h"
#include "screen.h"
#include <string>

#ifdef X_WINDOW_SYSTEM
  #include "xwindow.h"
  typedef quarrel::xwindow native_window;
#endif

namespace quarrel{
  /**
    * The main entry point for clients
    */
  class engine{
  private:
    window* game_window;
    keyboard keyboard_input;
    mouse mouse_input;
    const screen& current_screen;
  public:
    /**
      * Constructs a new engine instance, passing the given parameters
      * to construct the window that will contain the game
      * @param window_title The title of the game window
      * @param window_width The width of the game window
      * @param window_height The height of the game window
      **/
    engine(std::string window_title, uint window_width, uint window_height, const screen& base_screen);
    ~engine();

    void set_screen(const screen& scr);

    /**
      * Gets the keyboard input system so the user can query it
      * for key states
      * @return a const reference to the internal keyboard representation
      **/
    const keyboard& get_keyboard() const;

    /**
      * Gets the mouse input system so the user can query it for
      * the mouse state
      * @return a const reference to the internal mouse representation
      **/
    const mouse& get_mouse() const;

    /**
      * Runs the event loop of this engine instance, looking for internal
      * events to respond to
      **/
    void event_loop(void);

    /**
      * Returns true while the game is still running
      * when this returns false, the client should be exited.
      * If subsequent calls are made to the engine, undefined behavior is
      * invocted
      * @return true if the game is running
      **/
    bool is_running(void) const;
  };
}

#endif
