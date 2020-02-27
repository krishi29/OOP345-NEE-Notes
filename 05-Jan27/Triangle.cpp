#include <iostream>
using namespace std;
#include "Triangle.h"
double Triangle::area()const {
   return double(hieght) * base / 2;
}
istream& Triangle::read(istream& is) {
   cout << "Enter hieght/base: ";
   is >> hieght;
   is.ignore();
   return is >> base;
}