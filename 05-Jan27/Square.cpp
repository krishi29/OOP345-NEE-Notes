#include <iostream>
#include <typeinfo>
using namespace std;
#include "Square.h"
bool Square::operator==(const Figure& F)const {
   bool res = false;
   if (typeid(*this) == typeid(F)) {
      const Square* rt = dynamic_cast<const Square*>(&F);
      res = (this->width == rt->width);
   }
   return res;
}
void Square::setWidth(int value) {
   width = value;
}
int Square::getWidth()const {
   return width;
}
double Square::area()const {
   return double(width) * double(width);
}
ostream& Square::draw(ostream& os)const {
   for (int i = 0; i < width; i++) {
      for (int j = 0; j < width * 2; j++) {
         os << "*";
      }
      os << endl;
   }
   return os << "Area: " << width << "x" << width << "=" << area() << endl;
}
istream& Square::read(istream& is) {
   cout << "Enter width: ";
   return is >> width;
}
Figure* Square::clone()const {
   return new Square(*this);
}