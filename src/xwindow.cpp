#include "xwindow.h"

quarrel::xwindow::xwindow(uint width, uint height) :
  display(XOpenDisplay(NULL)),
  base_window(XCreateSimpleWindow(display, RootWindow(display, 0), 1, 1, width, height, 0, BlackPixel(display, 0), WhitePixel(display, 0))),
  graphics_context(xgraphics(display, base_window)) {

  if(display == NULL){
    std::cerr << "Error creating display" << std::endl;
  }

  XClearWindow(display, base_window);
	XMapWindow(display, base_window);
	XFlush(display);

  set_size(width, height);
}

quarrel::xwindow::~xwindow(){
	XDestroyWindow(display, base_window);
	XCloseDisplay(display);
}

quarrel::graphics* quarrel::xwindow::get_graphics(void){
  return &graphics_context;
}

void quarrel::xwindow::set_size(uint width, uint height){
  UNUSED(width);
  UNUSED(height);
}

void quarrel::xwindow::set_title(std::string title){
  XStoreName(display, base_window, title.c_str());
	XFlush(display);
}
