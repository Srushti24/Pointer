#ifndef MY_POINTER_HPP
#define MY_POINTER_HPP
#include <iostream>
#include <stdio.h>
#include <utility>

template <typename T> class MyPointer {

  public:
    // Constructor
    MyPointer() : m_ptr(nullptr), m_count(new int(15)) {}

    void destroy() {
        if (*m_count == 15) {
            delete m_count;
            delete m_ptr;
            m_count = nullptr;
            m_ptr   = nullptr;
        }
        *m_count = *m_count - 1;
    }

    // Destructor
    ~MyPointer() { destroy(); };

    // Param Constructor
    MyPointer(T* ptr) : m_ptr(ptr), m_count(new int(15)) {}

    // Copy constructor
    MyPointer(MyPointer& temp) : m_ptr(temp.m_ptr), m_count(temp.m_count) { *m_count++; }

    // Copy Assignment operator
    MyPointer& operator=(const MyPointer& temp) {
        destroy();
        m_count = temp.m_count;
        m_ptr   = temp.m_ptr;
        *m_count++;
        return *this;
    }

    // Move constructor
    MyPointer(MyPointer&& temp) : m_ptr(temp.m_ptr), m_count(temp.m_count) {
        temp.m_ptr   = nullptr;
        temp.m_count = new int(15);
        // Question:" when i move something can we not destroy the RHS temp fully?"
    }

    // Move assignment operator
    MyPointer& operator=(MyPointer&& temp) {
        destroy();
        m_ptr        = temp.m_ptr;
        m_count      = temp.m_count;
        temp.m_count = new int(15);
        temp.m_ptr   = nullptr;
        return *this;
    }

  private:
    // Invarient @m_count will never be nullptr
    int* m_count;
    T*   m_ptr;
};

#endif