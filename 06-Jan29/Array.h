template <typename type>
class Array {
   type* m_data = nullptr;
   unsigned int m_size;
public:
   Array(unsigned int size = 1);
   Array(const Array<type>& CP);
   Array<type>& operator=(const Array<type>& RO);
   Array(Array<type>&& CP);
   Array<type>& operator=(Array<type>&& RO);
   unsigned int size()const;
   void resize(unsigned int newsize);
   type& at(unsigned int index);
   type& operator[](unsigned int index);
   virtual ~Array();
};

template <typename type>
Array<type>::Array(unsigned int size) :m_size(size) {
   if (m_size == 0) m_size = 1;
   m_data = new type[m_size];
}

template <typename type>
unsigned int Array<type>::size()const {
   return m_size;
}


template <typename type>
void Array<type>::resize(unsigned int newsize) {
   unsigned int i;
   if (newsize == 0) newsize = 1;
   type* temp = new type[newsize];
   for (i = 0; i < m_size && i < newsize; i++) {
      temp[i] = m_data[i];
   }
   delete[] m_data;
   m_data = temp;
   m_size = newsize;
}


template <typename type>
type& Array<type>::at(unsigned int index) {
   if (index >= m_size) resize(index + 1);
   return m_data[index];
}

template <typename type>
type& Array<type>::operator[](unsigned int index) {
   return at(index);
}

template <typename type>
Array<type>::~Array() {
   delete[] m_data;
}
template <typename type>
Array<type>::Array(const Array<type>& CP) {
   operator=(CP);
}
template <typename type>
Array<type>& Array<type>::operator=(const Array<type>& RO) {
   if (this != &RO) {
      delete[] m_data;
      m_data = new type[m_size = RO.size()];
      for (unsigned int i = 0; i < m_size; i++) m_data = RO.m_data;
   }
   return *this;
}

template <typename type>
Array<type>::Array(Array<type>&& CP) {
   operator=(std::move(CP));
}
template <typename type>
Array<type>& Array<type>::operator=(Array<type>&& RO) {
   if (this != &RO) {
      delete[] m_data;
      m_data = RO.m_data;
      RO.m_data = new type[1];
      m_size = RO.m_size;
      RO.size = 1;
   }
   return *this;
}

