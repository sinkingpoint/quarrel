#include "log.h"
#include <iostream>

std::string quarrel::record::str() const{
  return record_builder.str();
}

void quarrel::logger::info(quarrel::record rec) const{
  std::cout << "[INFO] " << rec.str() << std::endl;
}

void quarrel::logger::debug(quarrel::record rec) const{
  std::cout << "[DEBUG] " << rec.str() << std::endl;
}

void quarrel::logger::error(quarrel::record rec) const{
  std::cout << "[ERROR] " << rec.str() << std::endl;
}
