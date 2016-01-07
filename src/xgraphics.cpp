#include "xgraphics.h"
#include <iostream>
#include <string>
#include "color.h"

quarrel::xgraphics::xgraphics(Display* display, Window window) :
  display(display),
  window(window),
  context(XCreateGC(display, window, 0, NULL)){

  XWindowAttributes attrs;
  XGetWindowAttributes(display, window, &attrs);
  std::cout << "Creating buffer of size " << attrs.width << "x" << attrs.height << " with depth: " << attrs.depth << std::endl;
  buffer = XCreatePixmap(display, window, attrs.width, attrs.height, attrs.depth);

  width = attrs.width;
  height = attrs.width;
}

void quarrel::xgraphics::clear(void){
  XFillRectangle(display, buffer, context, 0, 0, width, height);
}

void quarrel::xgraphics::set_color(unsigned int color){
  XSetForeground(display, context, color);
}

void quarrel::xgraphics::set_color(quarrel::color color){
  XSetForeground(display, context, color.get());
}

void quarrel::xgraphics::fill_rectangle(int x, int y, uint w, uint h){
	XFillRectangle(display, buffer, context, x, y, w, h);
}

void quarrel::xgraphics::draw_rectangle(int x, int y, uint w, uint h){
	XDrawRectangle(display, buffer, context, x, y, w, h);
}

void quarrel::xgraphics::fill_ellipse(int x, int y, unsigned int w, unsigned int h){
  XFillArc(display, buffer, context, x, y, w, h, 0, 360 * 64);//X takes angles in <angle * 64> for some reason
}

void quarrel::xgraphics::draw_ellipse(int x, int y, unsigned int w, unsigned int h){
  XDrawArc(display, buffer, context, x, y, w, h, 0, 360 * 64);//X takes angles in <angle * 64> for some reason
}

void quarrel::xgraphics::draw_line(int x1, int y1, int x2, int y2){
  XDrawLine(display, buffer, context, x1, y1, x2, y2);
}

void quarrel::xgraphics::draw_string(int x, int y, std::string str){
  XDrawString(display, buffer, context, x, y, str.c_str(), str.length());
}

void quarrel::xgraphics::draw_arc(int x, int y, unsigned int w, unsigned int h, int angle1, int angle2){
  XDrawArc(display, buffer, context, x, y, w, h, angle1 * 64, angle2 * 64);
}

void quarrel::xgraphics::fill_arc(int x, int y, unsigned int w, unsigned int h, int angle1, int angle2){
  XFillArc(display, buffer, context, x, y, w, h, angle1 * 64, angle2 * 64);
}

void quarrel::xgraphics::swap_buffer(){
  XCopyArea(display, buffer, window, context, 0, 0, width, height, 0, 0);
  XSync(display, false);
}

void quarrel::xgraphics::draw_image(int x, int y, quarrel::image img){
  for(unsigned int _x = 0;_x < img.get_width();_x ++){
    for(unsigned int _y = 0;_y < img.get_height();_y ++){
      set_color(img.get_pixel(_x, _y));
      fill_rectangle(x + _x, y + _y, 1, 1);
    }
  }
}
