cmake_minimum_required (VERSION 2.8.11)
project (testbed)

file(GLOB testbed_src "src/*.cpp")
set(CMAKE_BUILD_TYPE Debug)

add_executable(testbed ${testbed_src})
add_library(quarrel SHARED ${testbed_src})

include_directories("lib")

add_definitions("-std=c++11")

find_package(X11 REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

if (X11_FOUND)
  message (STATUS "Including X11 Libaries from " ${X11_INCLUDE_DIR})
  message (STATUS "Linking against X11 Libaries from " ${X11_LIBRARIES})
  include_directories (${X11_INCLUDE_DIR})
  target_link_libraries(testbed ${X11_LIBRARIES})
  target_link_libraries(quarrel ${X11_LIBRARIES})
endif (X11_FOUND)

find_package(PNG REQUIRED)
if (PNG_FOUND)
  message (STATUS "Including PNG Libaries from " ${PNG_INCLUDE_DIR})
  message (STATUS "Linking against PNG Libaries from " ${PNG_LIBRARIES})
  include_directories (${PNG_INCLUDE_DIR})
  target_link_libraries(testbed ${PNG_LIBRARIES})
  target_link_libraries(quarrel ${PNG_LIBRARIES})
endif (PNG_FOUND)

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(PUBLIC testbed "-pthread")
  target_compile_options(PUBLIC quarrel "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(testbed "${CMAKE_THREAD_LIBS_INIT}")
  target_link_libraries(quarrel "${CMAKE_THREAD_LIBS_INIT}")
endif()
