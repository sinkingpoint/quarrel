#ifndef QUARREL_EVENT_HANDLER_H
#define QUARREL_EVENT_HANDLER_H
#include <memory>
#include <vector>
#include "event.h"

namespace quarrel{
  class eventhandler{
  public:
    virtual std::vector<std::shared_ptr<event>> get_all_events() = 0;
  };
}

#endif
