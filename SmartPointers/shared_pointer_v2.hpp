
#include <stdio.h>

template <typename T> class SharedPointerV2 {

  public:
    // Constructor
    SharedPointerV2() : m_ptr(nullptr), m_count(nullptr) { std::cout << "inside constructor \n"; };

    // Destructor
    ~SharedPointerV2() { destroy(); }

    void destroy() {
        std::cout <<"inside destroy \n";
        if (m_count == nullptr) {
          std::cout << "inside m_count destroy \n";
            delete m_ptr;
            m_ptr = nullptr;
        } else {
            *m_count =  *m_count -1;
            if(*m_count == 0 )
            {
              delete m_ptr;
              m_ptr = nullptr;
            }
          }
    }

    // Param constructor
    SharedPointerV2(T* temp) : m_ptr(temp){ 
      m_count = temp == nullptr ? nullptr : new int(1);
      std::cout << "inside param constructor \n"; 
    }

    // Copy Assigment operator
    SharedPointerV2& operator=(const SharedPointerV2& temp) {
        std::cout << "Copy Assigment operator \n";
        destroy();
        m_count = temp.m_count;
        m_ptr   = temp.m_ptr;
        if(m_count != nullptr)
          {
            *m_count = *m_count + 1;
          }
        std::cout << "successful copy " << std::endl;
        std::cout << "m_count is  " <<  m_count << std::endl;
        std::cout << "temp m_count is"  << temp.m_count << std::endl;
        std::cout << " m_ptr is " << m_ptr << std::endl;
        std::cout << " temp m_ptr is " << temp.m_ptr << std::endl;
        std::cout << "m_count value is " << *m_count << std::endl;
        return *this;
    }

    // Copy constructor
    SharedPointerV2(const SharedPointerV2& temp) : m_ptr(temp.m_ptr), m_count(temp.m_count) {
        if(m_ptr != nullptr)
        {
          *m_count = *m_count+1;
        }
    }

    // Move Constructor
    SharedPointerV2(SharedPointerV2&& temp) : m_count(temp.m_count), m_ptr(temp.m_ptr) {
        std::cout << "move constructor \n";
        temp.m_count = nullptr;
        temp.m_ptr   = nullptr;
    }

    // Move Assignmenet operator
    SharedPointerV2 operator=(SharedPointerV2&& temp) {
        std::cout << "Move Assignmenet operator \n" ;
        destroy();
        m_count      = temp.m_count;
        m_ptr        = temp.m_ptr;
        temp.m_count = nullptr;
        temp.m_ptr   = nullptr;
    }
   
    T* operator->()
    {
      return m_ptr;
    }

     T* get()
    {
      return m_ptr;
    }

    T& operator*()
    {
      return *m_ptr;
    }
  private:
    T* m_ptr;
    //Invarient: When m_ptr is nullptr, m_count will be nullptr
    //When m_ptr is not null @m_count will not be null and the reference value of the @m_count pointer
    //will be minimum 1.
    int* m_count;
};
