cmake_minimum_required (VERSION 2.8.11)
project (Quarrel)

file(GLOB quarrel_src "src/*.cpp")
set(CMAKE_BUILD_TYPE Debug)

add_executable(quarrel ${quarrel_src})

include_directories("lib")

add_definitions("-std=c++11")

find_package(X11 REQUIRED)

if (X11_FOUND)
  message (STATUS "Including X11 Libaries from " ${X11_INCLUDE_DIR})
  message (STATUS "Linking against X11 Libaries from " ${X11_LIBRARIES})
  include_directories (${X11_INCLUDE_DIR})
  target_link_libraries(quarrel ${X11_LIBRARIES})
endif (X11_FOUND)

find_package(PNG REQUIRED)
if (PNG_FOUND)
  message (STATUS "Including PNG Libaries from " ${PNG_INCLUDE_DIR})
  message (STATUS "Linking against PNG Libaries from " ${PNG_LIBRARIES})
  include_directories (${PNG_INCLUDE_DIR})
  target_link_libraries(quarrel ${PNG_LIBRARIES})
endif (PNG_FOUND)
