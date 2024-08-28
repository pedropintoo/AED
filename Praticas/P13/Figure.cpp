//
// Algoritmos e Estruturas de Dados - 2023/2024
//
// J. Madeira - May 2022
//

#include "Figure.h"

#define _USE_MATH_DEFINES

#include <iostream>
#include <string>

#include "Point.h"

#define RAND_CENTER_LIMIT 20

std::string colors[5] = {"black", "red", "blue", "yellow","green"};

Figure::Figure(void) : center_(Point(0.0, 0.0)), color_("black") {}

Figure::Figure(Point center, const std::string& color)
    : center_(center), color_(color) {}

Figure::Figure(double x, double y, const std::string& color)
    : center_(Point(x, y)), color_(color) {}

Figure::Figure(int random) : center_(Point(rand()%RAND_CENTER_LIMIT+1.0,rand()%RAND_CENTER_LIMIT+1.0)), color_(colors[rand()%5]) {}

Point Figure::GetCenter(void) const { return center_; }
void Figure::SetCenter(Point center) { center_ = center; }

std::string Figure::GetColor(void) const { return color_; }
void Figure::SetColor(const std::string& color) { color_ = color; }
