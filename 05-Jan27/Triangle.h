#ifndef SDDS_TRIANGLE_H__
#define SDDS_TRIANGLE_H__
#include <iostream>
#include "Figure.h"

class Triangle :public Figure {
protected:
   int hieght{ 0 }, base{ 0 };
public:
   double area()const;
   std::istream& read(std::istream& is);
};



#endif