cmake_minimum_required (VERSION 2.8.11)
project (Quarrel)

file(GLOB quarrel_src "src/*.cpp")

add_executable(quarrel ${quarrel_src})

include_directories("lib")
target_link_libraries(quarrel ${ImageMagick_LIBRARIES})
