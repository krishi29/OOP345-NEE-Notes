#include <iostream>
#include <typeinfo>
using namespace std;

#include "Rectangle.h"
void Rectangle::set(int height, int width) {
   setWidth(width);
   this->hieght = height;
}
int Rectangle::getHieght()const {
   return hieght;
}

double Rectangle::area() const {
   return double(getHieght()) * double(getWidth());
}
ostream& Rectangle::draw(ostream& os) const {
   for (int i = 0; i < getHieght(); i++) {
      for (int j = 0; j < getWidth() * 2; j++) {
         os << "*";
      }
      os << endl;
   }
   return os << "Area: " << getHieght() << "x" << getWidth() << "=" << area() << endl;

}
istream& Rectangle::read(istream& is) {
   cout << "Enter hieght: ";
   is >> hieght;
   return Square::read(is);
}
bool Rectangle::operator==(const Figure& F)const {
   bool res = false;
   if (typeid(*this) == typeid(F)) {
      const Rectangle* rt = dynamic_cast<const Rectangle*>(&F);
      res = (getWidth() == rt->getWidth() && getHieght() == rt->getHieght());
   }
   return res;
}
Figure* Rectangle::clone()const {
   return new Rectangle(*this);
}