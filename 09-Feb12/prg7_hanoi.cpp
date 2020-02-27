#include <iostream>
using namespace std;
void hanoi(int n, char ta, char tb, char tc) {
   static int a = 1;
   if (n == 1) {
      cout << a++ << " - move from " << ta << " to " << tb << endl;
   }
   else {
      hanoi(n - 1, ta, tc, tb);
      cout << a++ << " - move from " << ta << " to " << tb << endl;
      hanoi(n - 1, tc, tb, ta);
   }
}

int main() {
   hanoi(4, 'A', 'B', 'C');
   return 0;
}