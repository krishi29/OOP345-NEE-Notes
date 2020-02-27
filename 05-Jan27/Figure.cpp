#include <iostream>
using namespace std;
#include "Figure.h"
Figure::~Figure() {
};

ostream& operator<<(ostream& os, const Figure& F) {
   return F.draw(os);
}
istream& operator>>(istream& is, Figure& F) {
   return F.read(is);
}

bool Figure::operator>(const Figure& F)const {
   return this->area() > F.area();
}