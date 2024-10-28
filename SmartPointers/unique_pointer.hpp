
#ifndef UNIQUE_POINTER_HPP
#define UNIQUE_POINTER_HPP

#include <iostream>
#include <stdio.h>
#include <utility>

template <typename P> class UniquePointer {

  private:
    P* m_ptr;

  public:
    UniquePointer() : m_ptr(nullptr) {}

    ~UniquePointer() {
        // delete m_ptr;
        destroy();
    }

    UniquePointer(P* ptr) : m_ptr(ptr) {}

    P* ptr() { return this->m_ptr; }

    void destroy() {
        if (m_ptr) {
            delete m_ptr;
            m_ptr = nullptr;
        }
    }

    P* operator->() { return m_ptr; }

    P& operator*() { return *m_ptr; }

    P* release() {
        P* temp_ptr = m_ptr;
        m_ptr       = nullptr; // Avoid double deletion
        return temp_ptr;
    }

    void reset(P* new_ptr) {
        destroy();
        m_ptr = new_ptr;
    }

    UniquePointer(const UniquePointer&) = delete;

    UniquePointer& operator=(const UniquePointer&) = delete;

    UniquePointer(UniquePointer&& ptr2) : m_ptr(ptr2.m_ptr) { ptr2.m_ptr = nullptr; }

    UniquePointer& operator=(UniquePointer&& ptr2) {
        if (this != &ptr2) {
            destroy();
            m_ptr      = ptr2.m_ptr;
            ptr2.m_ptr = nullptr;
        }
        return *this;
    }
};

template <typename T, typename... Args> UniquePointer<T> make_unique(Args&&... args) {
    return UniquePointer<T>(new T(std::forward<Args>(args)...));
}

#endif /* unique_pointer_hpp */
