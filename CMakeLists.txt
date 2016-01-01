cmake_minimum_required (VERSION 2.8.11)
project (Quarrel)

file(GLOB quarrel_src "src/*.cpp")

add_executable(quarrel ${quarrel_src})

include_directories("lib")

add_definitions("-std=c++11 -g")

find_package(X11 REQUIRED)

if (X11_FOUND)
  message (STATUS "Including X11 Libaries from " ${X11_INCLUDE_DIR})
  message (STATUS "Linking against X11 Libaries from " ${X11_LIBRARIES})
  include_directories (${X11_INCLUDE_DIR})
  target_link_libraries(quarrel ${X11_LIBRARIES})
endif (X11_FOUND)

target_link_libraries(quarrel ${X11})
