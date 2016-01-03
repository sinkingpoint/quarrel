#ifndef QUARREL_EVENT_HANDLER_H
#define QUARREL_EVENT_HANDLER_H
#include <memory>
#include <vector>
#include "event.h"

namespace quarrel{
  /**
    * An abstract event handler class which has methods for interfacing with
    * events in the system.
    **/
  class eventhandler{
  public:
    virtual std::vector<std::shared_ptr<event>> get_all_events() = 0;
  };
}

#endif
