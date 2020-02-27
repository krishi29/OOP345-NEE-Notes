#ifndef SDDS_RECTANGLE_H__
#define SDDS_RECTANGLE_H__
#include <iostream>
#include "Square.h"

class Rectangle : public Square {
   int hieght{ 0 };
public:
   void set(int height, int width);
   int getHieght()const;
   double area() const;
   std::ostream& draw(std::ostream& os) const;
   std::istream& read(std::istream& is);
   bool operator==(const Figure& F)const;
   Figure* clone()const;
};
#endif