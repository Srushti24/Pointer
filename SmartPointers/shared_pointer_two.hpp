
#include <stdio.h>

template <typename T> class SharedPointerNull {

  public:
    // Constructor
    SharedPointerNull() : m_ptr(nullptr), m_count(nullptr) { std::cout << "inside constructor \n"; };

    // Destructor
    ~SharedPointerNull() { destroy(); }

    void destroy() {
        std::cout <<"inside destroy \n";
        if (m_count == nullptr) {
          std::cout << "inside m_count destroy \n";
            delete m_ptr;
            m_ptr = nullptr;
        } else {
            *m_count =  *m_count -1;
            if(*m_count == 0)
            {
              std::cout << "m_count is zero so delete it \n";
              delete m_count;
              m_count = nullptr;
            }
          }
    }

    // Param constructor
    SharedPointerNull(T* temp) : m_ptr(temp), m_count(nullptr) { std::cout << "inside param constructor \n"; }

    void increment() {
        std::cout << "inside increment \n";
        if (m_count == nullptr) {
            m_count = new int(1);
            std::cout << "now m_count is " << *m_count << "\n";
        } else {
            *m_count = *m_count + 1;
        }
    }

    // Copy Assigment operator
    SharedPointerNull& operator=(const SharedPointerNull& temp) {
        std::cout << "Copy Assigment operator \n";
        destroy();
        m_count = temp.m_count;
        m_ptr   = temp.m_ptr;
        increment();
    }

    // Copy constructor
    SharedPointerNull(const SharedPointerNull& temp) : m_ptr(temp.m_ptr), m_count(temp.m_count) {
        std::cout << "Copy constructor \n";
        increment();
    }

    // Move Constructor
    SharedPointerNull(SharedPointerNull&& temp) : m_count(temp.m_count), m_ptr(temp.m_ptr) {
        std::cout << "move constructor \n";
        temp.m_count = nullptr;
        temp.m_ptr   = nullptr;
    }

    // Move Assignmenet operator
    SharedPointerNull operator=(SharedPointerNull&& temp) {
        std::cout << "Move Assignmenet operator \n" ;
        destroy();
        m_count      = temp.m_count;
        m_ptr        = temp.m_ptr;
        temp.m_count = nullptr;
        temp.m_ptr   = nullptr;
    }

  private:
    T* m_ptr;
    //Invarient: When there is only one pointer pointing to our object we will keep this count as nullptr.
    //@m_count at any point represent number of duplicate pointers poiting to that object apart from the first one.
    int* m_count;
};
