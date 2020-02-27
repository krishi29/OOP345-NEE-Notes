#include <iostream>
using namespace std;

void foo(int n) {
   if (n == 1)
      throw "Hello";
   else if (n == 2) {
      throw 5;
   }
   else if( n==3){
      throw 5.5;
   }
   else {
      cout << "nothing here!" << endl;
   }
}

int main() {
   int i;
   for (i = 0; i < 4; i++) {

      try {
         foo(i);
         cout << "I am here" << endl;
      }
      catch (double d) {
         cout << d << endl;
      }
      catch (int a) {
         cout << a << endl;
      }
      catch (const char* mes) {
         cout << mes << endl;
      }

   }

   return 0;
}