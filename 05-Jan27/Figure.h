#ifndef SDDS_FIGURE_H__
#define SDDS_FIGURE_H__
#include <iostream>
class Figure {
public:
   virtual double area() const = 0;
   virtual std::ostream& draw(std::ostream& os) const = 0;
   virtual std::istream& read(std::istream& is) = 0;
   virtual bool operator==(const Figure& F)const = 0;
   virtual bool operator>(const Figure& F)const;
   virtual Figure* clone()const = 0;
   virtual ~Figure();
};
ostream& operator<<(ostream& os, const Figure& F);
istream& operator>>(istream& is, Figure& F);


#endif