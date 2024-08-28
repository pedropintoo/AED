//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - May 2022
//

#ifndef FIGURE_H_
#define FIGURE_H_

#include <iostream>
#include <string>

#include "Point.h"

class Figure {
 public:
  Figure(void);
  Figure(Point center, const std::string& color);
  Figure(double x, double y, const std::string& color);
  Figure(int random);
  virtual ~Figure(void) = default; // implementação padrão para o destrutor

  Point GetCenter(void) const;
  void SetCenter(Point center);
  std::string GetColor(void) const;
  void SetColor(const std::string& color);

  virtual std::string GetClassName(void) const = 0; // virtual -> abstrata, necessita de implementação dos filhos
  virtual double Area(void) const = 0;
  virtual double Perimeter(void) const = 0;

 private:
  Point center_;
  std::string color_;
};

#endif  // FIGURE_H_
