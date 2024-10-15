#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP
#include <utility>
#include <iostream>
#include <stdio.h>

template <typename T> class SharedPointer {

  public:
    SharedPointer() : m_ptr(nullptr), count(new int(1)) {
        std::cout << "Called Shared Constructor \n";
    }

    SharedPointer(T* ptr) : m_ptr(ptr), count(new int(1)) {
        std::cout << "called  Shared Paramatized Constructor \n";
    }

    SharedPointer(const SharedPointer& p) : m_ptr(p.m_ptr), count(p.count) { 
        std::cout << "called  Shared Copy Constructor \n";
        (*count)++; 
        }
    
    ~SharedPointer() { 
        std::cout << " Shared Destructor \n";
        destroy(); }

    void destroy() {
        std::cout << " Shared Destroy Called \n";
        *count = *count - 1;
        if (*count == 0) {
            delete m_ptr;
            delete count;
        }
    }

    SharedPointer& operator=(const SharedPointer& p) {
        std::cout << " Copy Assigment Operator Called \n";
            destroy();
            m_ptr = p.m_ptr;
            count = p.count;
            (*count)++;
        return *this;
    }

    SharedPointer(SharedPointer&& p) : m_ptr(p.m_ptr), count(p.count) {
        std::cout << "Move Shared Constructor \n";
        p.m_ptr = nullptr;
    }

    SharedPointer operator=(SharedPointer&& p) {
        std::cout << "Move Shared Assigment Operator \n";
            destroy();
            m_ptr   = p.m_ptr;
            count   = p.count;
            p.m_ptr = nullptr;
           return *this;
    }

    T& operator*() { return *m_ptr; }

    T* operator->() { return m_ptr; }

    int use_count() const { return *count; }

    bool unique() const { return *count == 1; }

    void reset() {
        destroy();
        m_ptr = nullptr;
        count = new int(1);
    }

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


#endif