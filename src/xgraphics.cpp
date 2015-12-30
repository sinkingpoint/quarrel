#include "xgraphics.h"
#include <iostream>

quarrel::xgraphics::xgraphics(Display* display, Window window) :
  display(display),
  window(window),
  context(XCreateGC(display, window, 0, NULL)){
}

void quarrel::xgraphics::fill_rectangle(int x, int y, uint w, uint h){
  XSetForeground(display, context, BlackPixel(display, 0));
	XFillRectangle(display, window, context, x, y, w, h);
	XFlush(display);
}
