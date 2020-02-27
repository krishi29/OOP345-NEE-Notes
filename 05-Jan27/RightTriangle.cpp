#include <iostream>
using namespace std;
#include "RightTriangle.h"
bool RightTriangle::operator==(const Figure& F)const {
   bool res = false;
   if (typeid(*this) == typeid(F)) {
      const RightTriangle* rt = dynamic_cast<const RightTriangle*>(&F);
      res = (this->base == rt->base && this->hieght == rt->hieght);
   }
   else {
      cout << typeid(*this).name() << " is not the same as " << typeid(F).name() << endl;
   }
   return res;
}
ostream& RightTriangle::draw(ostream& os)const {
   double inc = double(base) * 2 / double(hieght);
   for (int i = 0; i < hieght; i++) {
      for (int j = 0; double(j) < i * inc + 1; j++) {
         os << "*";
      }
      os << endl;
   }
   cout << "Area: " << hieght << "x" << base << "/2=" << area() << endl;
   return os;
}
Figure* RightTriangle::clone()const {
   return new RightTriangle(*this);
}
bool RightTriangle::operator>(const Figure& F)const {
   Figure* rt = F.clone();
   return area() > F.area();
}