

#include <iostream>
using namespace std;
class Name {
private:
  char* m_value;//  = nullptr; // could have had it here
  static int strlen(const char* str) {
     const char* end = str;
     while (*end++);
     return static_cast<int>(end - str);
  }
  static void strcpy(char* des, const char* src) {
     while (*des++ = *src++);
  }
public:
  Name(const char* value = nullptr) :m_value(nullptr) {
    if (value) {
      int size = 0;
      m_value = new char[strlen(value) + 1];
      while (value[size++]);// size = strlen + 1
      m_value = new char[size--];  // allocate size then size-=1
                                   // strcopy backwards, firs null termination copied, if not at the first, go back once and opy the value, repeat
      for (m_value[size] = value[size]; size; m_value[--size] = value[size]);
    }
  }
  Name(const Name& N) {

  }
  ostream& print(ostream& os)const {
    if (m_value) os << m_value;
    return os;
  }
  ~Name() {
    delete[] m_value;
  }
};
ostream& operator<< (ostream& os, const Name& N) {
  os << "lvalue: ";
  return N.print(os);
}
ostream& operator<< (ostream& os,  Name&& N) {
  os << "rvalue: ";
  return N.print(os);
}
int main() {
  Name A = "Fred";
  cout << std::move(A) << endl;
  cout << Name("Joe") << endl;
  return 0;
}