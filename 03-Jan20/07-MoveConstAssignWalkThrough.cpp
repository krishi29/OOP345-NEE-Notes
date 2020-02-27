#define TRACE__  // comment to NOT to trace
#include <iostream>
using namespace std;
const int ReadBufferSize = 50;
const char* nl = "\n";
class Name;
ostream& operator<< (ostream& os, const Name& N);

class {
public:
   auto& operator<<(const char* message) {
#ifdef TRACE__
      cout << message;
#endif 
      return *this;
   }
   auto& operator<<(const Name& N) {
#ifdef TRACE__
      cout << N;
#endif 
      return *this;
   }
} trace;

class Name {
private:
   char* m_value  = nullptr; 
   static int strlen(const char* str) {
      const char* end = str;
      while (*end++);
      return static_cast<int>(end - str)-1;
   }
   static void strcpy(char* des, const char* src) {
      while (*des++ = *src++);
   }
   void allocateAndcopy(const char* value) {
      m_value = new char[strlen(value) + 1];
      strcpy(m_value, value);
   }
public:
   Name(const char* value = nullptr){
      if (value) {
         allocateAndcopy(value);
      }
      trace << "Creating " << *this << nl;
   }
   Name(const Name& N){
      trace << "Copying " << N << nl << "   ";
      operator=(N);
   }
   Name& operator=(const Name& N) {
      if (this != &N) {
         trace << "Assigning " << *this << " to " << N << nl;
         delete[] m_value;
         allocateAndcopy(N.m_value);
      }
      return *this;
   }
   Name& operator=(Name&& N) {
      if (this != &N) {
         trace << "(Move assignment), Moving " << N << " into " << *this << " by assignment" << nl;
         m_value = N.m_value;
         N.m_value = nullptr;
      }
      return *this;
   }
   Name(Name&& N) {
      trace << "(Move constructor), Taking ownership of " << N << " in a new Name" << nl << "    ";
      operator=(move(N));
   }
   ostream& print(ostream& os)const {
      if (m_value) 
         os << m_value; 
      else 
         os << "EMPTY NAME";
      return os;
   }
   istream& read(istream& is) { // reading any size of dynamically into name
      char* data = new char[ReadBufferSize];
      char* str = data;
      int noOfBuffers = 1;
      bool done;
      do {
         done = true;
         cin.getline(str, ReadBufferSize, '\n'); // if cin fails, it means entry was greater than 50 chars
         if (cin.fail()) {
            noOfBuffers++;  // keep track of number of buffers to add
            char* temp = new char[(ReadBufferSize - 1) * noOfBuffers + 1]; // allocate bigger memory
            strcpy(temp, data); // copy the already read test into temp
            delete[] data;  // delete the old (too short) memory
            data = temp;    // point to newly large allocated memory 
            str = data + (ReadBufferSize - 1) * (noOfBuffers - 1); // set the read pointer to continue reading the rest of text
            cin.clear();   // clear cin to read again
            done = false;  //we are not done yet
         }
      } while (!done);   // go back and continue reading if not done
      allocateAndcopy(data);
      delete[] data;
      return is;
   }
   ~Name() {
      trace << "Removing " << *this << " from memory" << nl;
      delete[] m_value;
   }
};
ostream& operator<< (ostream& os, const Name& N) {
   return N.print(os);
}
istream& operator>> (istream& is,  Name& N) {
   return N.read(is);
}
Name getName() {
   Name N;
   cout << "Enter a name: ";
   cin >> N;
   return N;
}
int main() {
   Name A = "Fred";
   Name B = A;
   Name C;
   cout << "A: " << A << endl;
   cout << "B: " << B << endl;
   cout << "C: " << C << endl;
   C = move(A);
   cout << "A: " << A << endl;
   cout << "B: " << B << endl;
   cout << "C: " << C << endl;
   Name D = getName();
   cout << "D: " << D << endl;
   Name E = move(B);
   cout << "E: " << E << endl;
   cout << "B: " << B << endl;
   return 0;
}