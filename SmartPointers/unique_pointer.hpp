//
//  unique_pointer.hpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#ifndef unique_pointer_hpp
#define unique_pointer_hpp

#include <stdio.h>
#include <utility>
#include <iostream>

template <typename P> class UniquePointer {

  private:
    P* m_ptr;

  public:
    UniquePointer() : m_ptr(nullptr) {
        std::cout<< "Unique Pointer Constructor called \n";
    }

    ~UniquePointer() {
        // delete m_ptr;
        std::cout<< "Unique Pointer Destructor called \n";
        destroy();
    }

    UniquePointer(P* ptr) : m_ptr(ptr) {
        std::cout<< "Unique Pointer Param Constructor called \n";
    }

    P* ptr() { return this->m_ptr; }

    void destroy() {
        delete m_ptr;
        m_ptr = nullptr; // why do this?
    }

    P* operator->() { return m_ptr; }

    P& operator*() { return *m_ptr; }

    P* release() {
        std::cout<< "Unique Pointer release called \n";
        P* temp_ptr = m_ptr;
        m_ptr       = nullptr; // Avoid double deletion
        return temp_ptr;
    }

    void reset(P* new_ptr) {
        std::cout<< "Unique Pointer reset called \n";
        destroy();
        m_ptr = new_ptr;
    }

    UniquePointer(const UniquePointer&) = delete;

    UniquePointer& operator=(const UniquePointer&) = delete;

    UniquePointer(UniquePointer&& ptr2) : m_ptr(ptr2.m_ptr) { ptr2.m_ptr = nullptr; }

    UniquePointer& operator=(UniquePointer&& ptr2) {
        std::cout<< "Unique Pointer move assignment called \n";
        if (this != &ptr2) {
            destroy();
            m_ptr      = ptr2.m_ptr;
            ptr2.m_ptr = nullptr;
        }
        return *this;
    }
};

template <typename T, typename... Args> UniquePointer<T> make_unique(Args&&... args) {
    std::cout<< "Unique Pointer make unique called \n";
    return UniquePointer<T>(new T(std::forward<Args>(args)...));
}

#endif /* unique_pointer_hpp */
