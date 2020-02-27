#define  _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
int main() {
   string token;
   char str[50];
   ifstream ifstr("prg.cpp");
   getline(ifstr, token, '\n');
   strcpy(str, token.c_str());
   cout << "first line:" << endl << str << endl;
   while (!getline(ifstr, token, ' ').fail()) {
      cout << token << "-";
   }
   cout << endl;
   return 0;
}