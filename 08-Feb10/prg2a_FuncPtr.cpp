#include <iostream>
using namespace std;
void add(int a, int b) {
   cout << a << "+" << b << "=" << (a + b) << endl;
}

int main() {
   void (*func)(int, int) = add;
   func(10, 2);
   return 0;
}