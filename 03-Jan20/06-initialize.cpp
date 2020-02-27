#include <iostream>
using namespace std;

int main() {
   const int n = 6;
   int a[] = { 1,2,3 };
   int b[]{ 1,2,3 };
   int c[5]{ 1,2,3 };
   int d[5]{};
   int* f = new int[n] { 1, 2, 3 };
   int* g = new int[n] {};

   for (int e : a) 
      cout << e;
   cout << '|' << endl;
   for (int e : b)
      cout << e;
   cout << '|' << endl;
   for (int e : c)
      cout << e;
   cout << '|' << endl;
   for (int e : d)
      cout << e;
   cout << '|' << endl;
   for (int i = 0; i < n; ++i)
      cout << f[i];
   cout << '|' << endl;
   for (int i = 0; i < n; ++i)
      cout << g[i];
   cout << '|' << endl;

   delete[] f;
   delete[] g;
}