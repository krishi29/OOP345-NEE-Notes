#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#include "Student.h"
double TAX = 0.13;
const double PI = 3.14159265;
namespace sdds {
   int Student::NoObj = 0;
   int Student::noOfInstances() {
      //cout << m_age;  m_age is not static
      return NoObj;
   }
   void Student::set(const char name[], int age) {
      strcpy(m_name, name);
      m_age = age;
   }
   void Student::print() {
      cout << m_name << endl;
      cout << m_age << endl;
   }

   Student::Student(const char name[], int age) {
      NoObj++;
      set(name, age);
   }
   Student::~Student() {
      NoObj--;
   }

}