
#include <iostream>

template <typename T> class SharedPointerV2 {

  public:
    // Constructor
    SharedPointerV2() : m_ptr(nullptr), m_count(nullptr) {};

    // Destructor
    ~SharedPointerV2() { destroy(); }

    void destroy() {
        if (m_count != nullptr) {
            *m_count = *m_count - 1;
            if (*m_count == 0) {
                delete m_ptr;
                delete m_count;
            }
        }
    }

    // Param constructor
    SharedPointerV2(T* temp) : m_ptr(temp) { m_count = temp == nullptr ? nullptr : new int(1); }

    // Copy Assigment operator
    SharedPointerV2& operator=(const SharedPointerV2& temp) {
        destroy();
        m_count = temp.m_count;
        m_ptr   = temp.m_ptr;
        if (m_count != nullptr) {
            *m_count = *m_count + 1;
        }
        return *this;
    }

    // Copy constructor
    SharedPointerV2(const SharedPointerV2& temp) : m_ptr(temp.m_ptr), m_count(temp.m_count) {
        if (m_ptr != nullptr) {
            *m_count = *m_count + 1;
        }
    }

    // Move Constructor
    SharedPointerV2(SharedPointerV2&& temp) : m_count(temp.m_count), m_ptr(temp.m_ptr) {
        temp.m_count = nullptr;
        temp.m_ptr   = nullptr;
    }

    // Move Assignmenet operator
    SharedPointerV2& operator=(SharedPointerV2&& temp) {
        destroy();
        m_count      = temp.m_count;
        m_ptr        = temp.m_ptr;
        temp.m_count = nullptr;
        temp.m_ptr   = nullptr;
        return *this;
    }

    T* operator->() { return m_ptr; }

    T* get() { return m_ptr; }

    T& operator*() { return *m_ptr; }

    int getCount() { return m_count == nullptr ? 0 : *m_count; }

  private:
    T* m_ptr;
    // Invarient: When m_ptr is nullptr, m_count will be nullptr
    // When m_ptr is not null @m_count will not be null and the reference value of the @m_count pointer
    // will be minimum 1.
    int* m_count;
};
