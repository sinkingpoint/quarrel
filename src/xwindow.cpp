#include "xwindow.h"

quarrel::xwindow::xwindow(uint width, uint height){
  display = XOpenDisplay(NULL);
  baseWindow = XCreateSimpleWindow(display, RootWindow(display, 0), 1, 1, width, height, 0, BlackPixel(display, 0), WhitePixel(display, 0));

  if(display == NULL){
    std::cerr << "Error creating display" << std::endl;
  }

  XClearWindow(display, baseWindow);
	XMapWindow(display, baseWindow);
	XFlush(display);

  set_title("Vimda");
  set_size(width, height);
}

quarrel::xwindow::~xwindow(){
	XDestroyWindow(display, baseWindow);
	XCloseDisplay(display);
}

void quarrel::xwindow::set_size(uint width, uint height){
  UNUSED(width);
  UNUSED(height);
}

void quarrel::xwindow::set_title(std::string title){
  XStoreName(display, baseWindow, title.c_str());
	XFlush(display);
}
