#include <iostream>
using namespace std;
int foo() {
   static int i{ 0 };
   i++;
   return i;
}
int main() {
   int j;
   for (j = 0; j < 5; j++) {
      cout << j + 1 << ": " << foo() << endl;
   }
   return 0;
}