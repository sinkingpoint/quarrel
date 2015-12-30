#include "xwindow.h"

quarrel::xwindow::xwindow(uint width, uint height) :
  display(XOpenDisplay(NULL)),
  base_window(XCreateSimpleWindow(display, RootWindow(display, 0), 1, 1, width, height, 0, BlackPixel(display, 0), WhitePixel(display, 0))),
  graphics_context(xgraphics(display, base_window)),
  ev_handler(xeventhandler(display)) {

  this->closed = false;

  if(display == NULL){
    std::cerr << "Error creating display" << std::endl;
  }
  XSelectInput(display, base_window, ExposureMask | KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask);

  Atom WM_DELETE_WINDOW = XInternAtom(display, "WM_DELETE_WINDOW", false);
  XSetWMProtocols(display, base_window, &WM_DELETE_WINDOW, 1);

  XClearWindow(display, base_window);
	XMapWindow(display, base_window);
	XFlush(display);

  set_size(width, height);
}

quarrel::xwindow::~xwindow(){
  if(display != 0){
    XDestroyWindow(display, base_window);
    XCloseDisplay(display);
  }
}

quarrel::graphics* quarrel::xwindow::get_graphics(void){
  return &graphics_context;
}

quarrel::eventhandler* quarrel::xwindow::get_eventhandler(void){
  return &ev_handler;
}

void quarrel::xwindow::close(){
  closed = true;
  XDestroyWindow(display, base_window);
  XCloseDisplay(display);
  display = NULL;
}

void quarrel::xwindow::set_size(uint width, uint height){
  UNUSED(width);
  UNUSED(height);
}

void quarrel::xwindow::set_title(std::string title){
  XStoreName(display, base_window, title.c_str());
	XFlush(display);
}
