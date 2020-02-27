#include <iostream>
using namespace std;
typedef unsigned int* uintptr;
//#define uintptr unsigned int* // will not work for line 7 since q becomes just an int 
int main() {
  uintptr p, q;
  unsigned int a = 20;
  p = &a;
  q = &a;
  cout << *p << endl;
  cout << *q << endl;
  return 0;
}