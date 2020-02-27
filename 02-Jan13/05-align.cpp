#include <iostream>
using namespace std;
struct foo {
   double i;
   char ch[5];
   double j;
   int k;
};
int main() {
   cout << sizeof(foo) << endl;
   return 0;
}