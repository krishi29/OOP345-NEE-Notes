#ifndef SDDS_RIGHTTRIANGLE_H__
#define SDDS_RIGHTTRIANGLE_H__
#include <iostream>
#include "Triangle.h"
class RightTriangle :public Triangle {
public:
   std::ostream& draw(std::ostream& os)const;
   bool operator==(const Figure& F)const;
   bool operator>(const Figure& F)const;
   Figure* clone()const;
};

#endif