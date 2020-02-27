#include <iostream>
using namespace std;
// command one two three
int main(int argc, char* argv[], char* env[]) {
   int i;

   cout << "Command line arguments: " << endl;
   for (i = 0; i < argc; i++) {
      cout << i + 1 << ": " << argv[i] << endl;
   }
   cout << "Environment Vairables: " << endl;
   for (i = 0; env[i]; i++) {
      cout << i + 1 << ": " << env[i] << endl;
   }

   return 1234;// goes to os, in  Windows type echo %ERRORLEVEL% to retrieve this value after execution
                // in linux echo $? will do the same
}