#include "xgraphics.h"
#include <iostream>
#include <string>

quarrel::xgraphics::xgraphics(Display* display, Window window) :
  display(display),
  window(window),
  context(XCreateGC(display, window, 0, NULL)){
}

void quarrel::xgraphics::clear(void){
  XClearWindow(display, window);
}

void quarrel::xgraphics::set_color(unsigned int color){
  XSetForeground(display, context, color);
}

void quarrel::xgraphics::fill_rectangle(int x, int y, uint w, uint h){
	XFillRectangle(display, window, context, x, y, w, h);
}

void quarrel::xgraphics::draw_rectangle(int x, int y, uint w, uint h){
	XDrawRectangle(display, window, context, x, y, w, h);
}

void quarrel::xgraphics::fill_ellipse(int x, int y, unsigned int w, unsigned int h){
  XFillArc(display, window, context, x, y, w, h, 0, 360 * 64);//X takes angles in <angle * 64> for some reason
}

void quarrel::xgraphics::draw_ellipse(int x, int y, unsigned int w, unsigned int h){
  XDrawArc(display, window, context, x, y, w, h, 0, 360 * 64);//X takes angles in <angle * 64> for some reason
}

void quarrel::xgraphics::draw_line(int x1, int y1, int x2, int y2){
  XDrawLine(display, window, context, x1, y1, x2, y2);
}

void quarrel::xgraphics::draw_string(int x, int y, std::string str){
  XDrawString(display, window, context, x, y, str.c_str(), str.length());
}

void quarrel::xgraphics::draw_arc(int x, int y, unsigned int w, unsigned int h, int angle1, int angle2){
  XDrawArc(display, window, context, x, y, w, h, angle1 * 64, angle2 * 64);
}

void quarrel::xgraphics::fill_arc(int x, int y, unsigned int w, unsigned int h, int angle1, int angle2){
  XFillArc(display, window, context, x, y, w, h, angle1 * 64, angle2 * 64);
}
