#ifndef SDDS_STUDENT_H__
#define SDDS_STUDENT_H__
extern double TAX;
extern const double PI;
namespace sdds {

   class Student {
   private:
      static int NoObj;
      char m_name[21];
      int m_age;
   public:
      Student(const char name[]="", int age= 0);
      static int noOfInstances();
      virtual ~Student();
      void set(const char name[], int age);
      void print();
   };

}

#endif