//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// COMPLETE the code, according to Rectangle.h
//

#include "Rectangle.h"

#include <cassert>
#include <iostream>
#include <string>

#include "Point.h"

#define RAND_HEIGHT_LIMIT 200
#define RAND_WIDTH_LIMIT 200

Rectangle::Rectangle(void)
 : Figure(), height_(1.0), width_(1.0) {
  // Rectangle of width=1 and height=1 and centered at (0,0)
  // COMPLETE
}

Rectangle::Rectangle(Point center, const std::string& color, double width,
                     double height)
                      : Figure(center, color), height_(height), width_(width) {
  // Ensure that the width and height are larger than 0.0
  // COMPLETE
  assert(width_ > 0 && height_ > 0);
}

Rectangle::Rectangle(double x, double y, const std::string& color, double width,
                     double height)
                      : Figure(x, y, color), height_(height), width_(width) {
  // Ensure that the width and height are larger than 0.0
  // COMPLETE
  assert(width_ > 0 && height_ > 0);
}

Rectangle::Rectangle(int random) : Figure(1), height_(rand()%RAND_HEIGHT_LIMIT+1.0), width_(rand()%RAND_WIDTH_LIMIT+1.0) {
}


double Rectangle::GetHeight(void) const { return height_; }
void Rectangle::SetHeight(double length) {
  // Ensure that the height is larger than 0.0
  // COMPLETE
  assert(length > 0);
  height_ = length;
}

double Rectangle::GetWidth(void) const { return width_; }
void Rectangle::SetWidth(double length) {
  // Ensure that the width is larger than 0.0
  // COMPLETE
  assert(length > 0);
  width_ = length;
}

std::string Rectangle::GetClassName(void) const { return "Rectangle"; }

double Rectangle::Area(void) const {
  // COMPLETE
  return width_*height_;
}

double Rectangle::Perimeter(void) const {
  // COMPLETE
  return width_*2+height_*2;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
  // COMPLETE
  os << "Center: " << obj.GetCenter() << std::endl;
  os << "Color: " << obj.GetColor() << std::endl;
  os << "Height = " << obj.height_ << std::endl;
  os << "Width = " << obj.width_ << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Rectangle& obj) {
  // COMPLETE
  Point center;
  std::cout << "Center: " << std::endl;
  is >> center;
  obj.SetCenter(center);

  std::cout << "height = ";
  is >> obj.height_; // internal value
  
  std::cout << "width = ";
  is >> obj.width_; // internal value

  std::string color;
  std::cout << "color = ";
  is >> color;
  obj.SetColor(color);

  return is;
}

