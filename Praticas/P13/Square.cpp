//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// COMPLETE the code, according to Square.h
//

#include "Square.h"

#include <cassert>
#include <iostream>
#include <string>

#include "Point.h"
#include "Rectangle.h"

#define RAND_EDGE_LIMIT 200

Square::Square(void) : Rectangle() {
  // Rectangle of edge=1 and centered at (0,0)
  // COMPLETE
}

Square::Square(Point center, const std::string &color, double length) : Rectangle(center, color, length, length) {}

Square::Square(double x, double y, const std::string &color, double length) : Rectangle(x, y, color, length, length) {}

Square::Square(int random) : Rectangle(1) {
  double edge = rand()%RAND_EDGE_LIMIT+1.0;
  SetWidth(edge);
  SetHeight(edge);
}

std::string Square::GetClassName(void) const {
  return "Square";
}

double Square::GetEdgeLength(void) const { return GetWidth();}

void Square::SetEdgeLength(double length) {
  SetWidth(length); // ja tem... assert(length > 0);
  SetHeight(length);
}

// WRITE THE MISSING CONSTRUTORS, METHODS AND FRIEND FUNCTIONS

std::ostream &operator<<(std::ostream &os, const Square &obj) {
  os << "Center: " << obj.GetCenter() << std::endl;
  os << "Color: " << obj.GetColor() << std::endl;
  os << "Edge = " << obj.GetWidth() << std::endl;
  return os;
}

std::istream &operator>>(std::istream &is, Square &obj) {

  Point center;
  std::cout << "Center: " << std::endl;
  is >> center;
  obj.SetCenter(center);

  double edge;
  std::cout << "edge = ";
  is >> edge;
  obj.SetEdgeLength(edge);
  
  std::string color;
  std::cout << "color = ";
  is >> color;
  obj.SetColor(color);

  return is;
}
