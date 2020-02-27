#include <iostream>
using namespace std;
#include "Int2.h"

int main() {
   Int val(0, [](int val, string& str) {str = "Invalid Mark value, [0<=mark<=100]: "; return val >= 0 && val <= 100; });
   cout << "Enter the mark: ";
   cin >> val;
   cout << "Your mark is: " << val << endl;
   return 0;
}