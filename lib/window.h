#ifndef QUARREL_WINDOW_H
#define QUARREL_WINDOW_H

#include <string>
#include "helpers.h"
#include "graphics.h"
#include "eventhandler.h"

namespace quarrel{

  /**
    * An abstract window class in some widow manager
    **/
  class window{
  private:
  protected:
    bool closed;
  public:
    window();

    virtual ~window();

    /**
      * Checks whether this window has been closed (either by the
      * user or otherwise). If this is true, the client should probably
      * do a clean up and exit. Nothing is being displayed.
      * @return true if the window is closed
      **/
    bool is_closed() const;

    /**
      * Marks this window as closed
      */
    virtual void close() = 0;

    /**
      * Sets the size of this window
      * @param width the new width of this window
      * @param height the new height of this window
      **/
    virtual void set_size(uint width, uint height) = 0;

    /**
      * Sets the title of this window that is displayed at the top of the
      * window (usually) by the window manager
      * @param title the new title of the window
      **/
    virtual void set_title(std::string title) = 0;

    /**
      * Gets the underlying graphics object which can be used to draw on
      * this window
      * @return a graphics reference which can be used to draw on this window
      **/
    virtual graphics& get_graphics(void) = 0;
    virtual eventhandler& get_eventhandler(void) = 0;
  };
}

#endif
