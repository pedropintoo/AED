//
// Algoritmos e Estruturas de Dados - 2023/2024
//

#include <iomanip>
#include <iostream>
#include <vector>

#include "Circle.h"
#include "Figure.h"
#include "Rectangle.h"
#include "Square.h"

#define RANDOM 1

int main(void) {
  Square square_1;
  std::cout << square_1;
  std::cout << std::endl;

  Rectangle rect_1;
  std::cout << rect_1;
  std::cout << std::endl;

  Circle circle_1;
  std::cout << circle_1;
  std::cout << std::endl;

  Circle circle_2(0.0, 0.0, "yellow", 2.0);
  std::cout << circle_2;
  std::cout << std::endl;

  std::cout << "The yellow circle intersects the black circle?" << std::endl; // intersecao entre circunferencias...
  std::cout << std::boolalpha << circle_1.Intersects(circle_2) << std::endl;
  std::cout << std::endl;

  Circle circle_3(1.0, 0.0, "red", 1.0);
  std::cout << circle_3;
  std::cout << std::endl;

  std::cout << "The red circle intersects the black circle?" << std::endl;
  std::cout << std::boolalpha << circle_1.Intersects(circle_3) << std::endl;

  std::vector<Figure*> figures;
  figures.push_back(&square_1);
  figures.push_back(&rect_1);
  figures.push_back(&circle_1);
  figures.push_back(&circle_2);
  figures.push_back(&circle_3);

  std::vector<Figure*> figuresRandom;
  srand(time(NULL));

  for (int i = 0; i < 10; i++) {
    Figure* randFig;
    switch(rand()%1) {
      case 0:
        randFig = new Circle(RANDOM);
        break;
      case 1:
        randFig = new Rectangle(RANDOM);
        break;
      case 2:
        randFig = new Square(RANDOM);
        break;
    }
    figuresRandom.push_back(randFig);
    
    Figure* checkFig = figuresRandom.back();
    std::cout << checkFig->GetClassName() << " - Area = " << checkFig->Area()
      << " - Perimeter = " << checkFig->Perimeter() 
      << " - Center = " << checkFig->GetCenter() << std::endl;

  }
  
  // free
  Figure* randFig;
  for (int i = 0; i < 10; i++) {
    randFig = figuresRandom.back();
    delete randFig;
    figuresRandom.pop_back();
  }

  return 0;
}