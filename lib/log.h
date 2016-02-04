#include <string>
#include <sstream>

namespace quarrel{

  enum severity{
    info,
    debug,
    error
  };

  class record{
  private:
    std::stringstream record_builder;
  public:
    record();
    record(const record&);

    template<class T>
    record& operator<<(T val){
      record_builder << val;
      return *this;
    }

    std::string str() const;
  };

  class logger{
  public:
    logger();
    void info(quarrel::record) const;
    void debug(quarrel::record) const;
    void error(quarrel::record) const;
  };

  const logger log;
}
