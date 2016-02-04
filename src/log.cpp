#include "log.h"
#include <iostream>

quarrel::record::record(){}
quarrel::record::record(const record& rec){
  record_builder << rec.str();
}

std::string quarrel::record::str() const{
  return record_builder.str();
}

quarrel::logger::logger(){
  
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
