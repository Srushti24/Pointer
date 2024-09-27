#include <utility>
#include <iostream>
#include <stdio.h>

template <typename T> class SharedPointer {

  public:
    // Constructor
    SharedPointer() : m_ptr(nullptr), count(new int(1)) {
        std::cout << "Called Shared Constructor \n";
    }

    // Paramatized Constructor
    SharedPointer(T* ptr) : m_ptr(ptr), count(new int(1)) {
        std::cout << "called  Shared Paramatized Constructor \n";
    }

    // Copy Constructor
    SharedPointer(const SharedPointer& p) : m_ptr(p.m_ptr), count(p.count) { 
        std::cout << "called  Shared Copy Constructor \n";
        (*count)++; 
        }
    
    // Destructor
    ~SharedPointer() { 
        std::cout << " Shared Destructor \n";
        destroy(); }

    // Destroy the object
    void destroy() {
        std::cout << " Shared Destroy Called \n";
        if(count == nullptr)
        {
            return;
        }
        *count = *count > 0 ? *count - 1 : *count;
        if (*count == 0) {
            delete m_ptr;
            delete count;
        }
    }

    // Copy assigment operator
    SharedPointer& operator=(const SharedPointer& p) {
        std::cout << " Copy Assigment Operator Called \n";
        if (this != &p) {
            destroy();
            m_ptr = p.m_ptr;
            count = p.count;
            (*count)++;
        }
        return *this;
    }

    // Move Constructor
    SharedPointer(SharedPointer&& p) : m_ptr(p.m_ptr), count(p.count) {
        std::cout << "Move Shared Constructor \n";
        p.m_ptr = nullptr;
        p.count = nullptr;
    }

    // Move Assigment operator
    SharedPointer operator=(SharedPointer&& p) {
        std::cout << "Move Shared Assigment Operator \n";
        if (this != &p) {
            destroy();
            m_ptr   = p.m_ptr;
            count   = p.count;
            p.m_ptr = nullptr;
            p.count = nullptr;
        }
        return *this;
    }

    // Dereferencing
    T& operator*() { return *m_ptr; }

    // Pointing
    T* operator->() { return m_ptr; }

    // Return use_count
    int use_count() const { return *count; }

    // calculate unique
    bool unique() const { return *count == 1; }

    // Reset
    void reset() {
        destroy();
        m_ptr = nullptr;
        count = new int(1);
    }

    // Paramatized reset
    void reset(SharedPointer& new_ptr) {
        destroy();
        m_ptr = new_ptr.m_ptr;
        count = new_ptr.count;
        *count++;
    }

    // release
    T* release() {
        std::cout << "release \n";
        if (m_ptr) {
            T* temp_ptr = m_ptr;
            *count      = *count > 0 ? *count - 1 : *count;
            if (*count == 0) {
                delete m_ptr;
                delete count;
            }
            m_ptr = nullptr;
            count = new int(1);
            return temp_ptr;
        }
        return nullptr;
    }

    // Swap two function
    void swap(SharedPointer& other) {
        std::swap(m_ptr, other.m_ptr);
        std::swap(count, other.count);
    }

  private:
    // Raw pointer used to point and count is the counter used to represent number of instances pointing to the same
    // object
    T*   m_ptr;
    int* count;
};

template <typename T, typename... Args> SharedPointer<T> make_shared(Args&&... args) {
    return SharedPointer<T>(new T(std::forward<Args>(args)...));
}