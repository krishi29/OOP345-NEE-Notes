#ifndef SDDS_KVP_H__
#define SDDS_KVP_H__
#include <iostream>
template <typename KeyType, typename ValueType, unsigned int ValSize>
class KVP {
   KeyType m_key {};
   ValueType m_val[ValSize] {};
public:
   std::istream& read(std::istream& is) {
      is >> m_key;
      for (unsigned int i = 0; i < ValSize; i++) {
         std::cout << (i + 1) << "/" << ValSize << ": ";
         is >> m_val[i];
         is.ignore(1000, '\n');
      }
      return is;
   }
   std::ostream& print(std::ostream& os)const {
      os << m_key << ": ";
      for (unsigned int i = 0; i < ValSize; i++) {
         os <<m_val[i];
         if (i != ValSize - 1) os << ", ";
      }
      return os;
   }
};
template <typename KeyType, typename ValueType, unsigned int ValSize>
std::ostream& operator<<(ostream& os, const KVP<KeyType, ValueType, ValSize>& kvp) {
   return kvp.print(os);
}
template <typename KeyType, typename ValueType, unsigned int ValSize>
std::istream& operator>>(istream& os,  KVP<KeyType, ValueType, ValSize>& kvp) {
   return kvp.read(os);
}


#endif // ! SDDS_KVP_H__
