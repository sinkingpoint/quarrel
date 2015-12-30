#include "xgraphics.h"
#include <iostream>

quarrel::xgraphics::xgraphics(Display* display, Window window) :
  display(display),
  window(window),
  context(XCreateGC(display, window, 0, NULL)){
}

void quarrel::xgraphics::fill_rectangle(int x, int y, uint w, uint h){
  std::cout << "Drawing Rectangle!" << std::endl;
  XSetForeground(display, context, BlackPixel(display, 0));
	XFillRectangle(display, window, context, 100, 100, 640, 100);
	XFlush(display);
}
