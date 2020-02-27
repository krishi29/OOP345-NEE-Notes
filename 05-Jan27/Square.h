#ifndef SDDS_SQUARE_H__
#define SDDS_SQUARE_H__
#include <iostream>
#include "Figure.h"

class Square : public Figure {
   int width{ 0 };
public:
   void setWidth(int value);
   int getWidth()const;
   double area() const;
   std::ostream& draw(std::ostream& os) const;
   std::istream& read(std::istream& is);
   bool operator==(const Figure& F)const;   
   Figure* clone()const;
};


#endif