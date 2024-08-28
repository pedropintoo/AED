//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// COMPLETE the code, according to Circle.h
//

#include "Circle.h"

#define _USE_MATH_DEFINES

#include <cassert>
#include <cmath>
#include <iostream>
#include <string>

#include "Figure.h"
#include "Point.h"

#define RAND_RADIUS_LIMIT 500

Circle::Circle(void) : Figure(), radius_(1.0) {
  // Circle of radius 1 and centered at (0,0)
  // COMPLETE
}

Circle::Circle(Point center, const std::string& color, double length)
 : Figure(center,color), radius_(length) {
  // Ensure that the radius is larger than 0.0
  // COMPLETE
  assert(length > 0.0);
}

Circle::Circle(double x, double y, const std::string& color, double length) : Figure(x,y,color), radius_(length) {
  // Ensure that the radius is larger than 0.0
  // COMPLETE
  assert(length > 0.0);
}

Circle::Circle(int random) : Figure(1), radius_(rand()%RAND_RADIUS_LIMIT+1.0) {
}

double Circle::GetRadius(void) const { return radius_; }
void Circle::SetRadius(double length) {
  // Ensure that the radius is larger than 0.0
  // COMPLETE
  assert(length > 0);
  radius_ = length;
}

std::string Circle::GetClassName(void) const { return "Circle"; }

double Circle::Area(void) const {
  // COMPLETE
  // Area = pi*r²
  return M_PI * pow(radius_, 2);
}

double Circle::Perimeter(void) const {
  // COMPLETE
  // Perimetro = 2*pi*r
  return 2 * M_PI * radius_;
}

bool Circle::Intersects(const Circle& c) const { // intersecao entre circunferencias!!!
  // |r1 - r2| < dist(C1,C2) < r1 + r2

  double distance_between_centers = GetCenter().DistanceTo(c.GetCenter());

  double sum_of_radii = radius_ + c.radius_;

  double absolute_difference_of_radii = std::abs(radius_ - c.radius_);

  return ((absolute_difference_of_radii < distance_between_centers) &&
          (distance_between_centers < sum_of_radii));
}

std::ostream& operator<<(std::ostream& os, const Circle& obj) {
  os << "Center: " << obj.GetCenter() << std::endl;
  os << "Color: " << obj.GetColor() << std::endl;
  os << "Radius = " << obj.radius_ << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Circle& obj) {
  // COMPLETE

  Point center;
  std::cout << "Center: " << std::endl;
  is >> center; // with Point operator
  obj.SetCenter(center);

  std::cout << "radius = ";
  is >> obj.radius_; // internal value

  std::string color;
  std::cout << "color = ";
  is >> color;
  obj.SetColor(color);

  return is;
  
}
