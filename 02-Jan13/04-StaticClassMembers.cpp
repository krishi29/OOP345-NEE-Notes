#include <iostream>
using namespace std;
#include "Student.h"
using namespace sdds;
int main() {
   cout << Student::noOfInstances() << endl;
   Student S;
   cout << S.noOfInstances() << endl;
   cout << Student::noOfInstances() << endl;
   return 0;
}