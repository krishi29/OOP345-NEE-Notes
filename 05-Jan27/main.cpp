#include <iostream>
using namespace std;
#include "RightTriangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Rectangle.h"

int main() {
   RightTriangle rt;
   Square s, t;
   Rectangle r;
   cout << "RightTriangle: " << endl;
   cin >> rt;
   cout << "Square: " << endl;
   cin >> s;
   cout << "Square: " << endl;
   cin >> t;
   cout << "Rectangle: " << endl;
   cin >> r;
   cout << rt << endl;
   cout << s << endl;
   cout << t << endl;
   cout << r << endl;
   if (rt == s) {
      cout << "the same" << endl;
   }
   else {
      cout << "Not the same" << endl;
   }
   if (s == t) {
      cout << "Both Squares have the with of " << s.getWidth() << endl;
   }
   else {
      cout << "the Squares are different with the following widths: " << s.getWidth() << " and " << t.getWidth() << endl;
   }
   if (s == r) {
      cout << "the same" << endl;
   }
   else {
      cout << "Not the same" << endl;
   }
   return 0;
}
