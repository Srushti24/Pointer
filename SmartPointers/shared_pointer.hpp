#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP
#include <iostream>
#include <stdio.h>
#include <utility>

template <typename T> class SharedPointer {

  public:
    SharedPointer() : m_ptr(nullptr), count(new int(1)) {}

    SharedPointer(T* ptr) : m_ptr(ptr), count(new int(1)) {}

    SharedPointer(const SharedPointer& p) : m_ptr(p.m_ptr), count(p.count) { (*count)++; }

    ~SharedPointer() { destroy(); }

    void destroy() {
        if (*count == 1) {
            delete m_ptr;
            delete count;
            m_ptr = nullptr;
            count = nullptr; // not breaking invarient why?
        } else {
            *count = *count - 1;
        }
    }

    SharedPointer& operator=(const SharedPointer& p) {
        destroy();
        m_ptr = p.m_ptr;
        count = p.count;
        (*count)++;
        return *this;
    }

    SharedPointer(SharedPointer&& p) : m_ptr(p.m_ptr), count(p.count) {
        p.m_ptr = nullptr;
        p.count = new int(1);
    }

    SharedPointer operator=(SharedPointer&& p) {
        destroy();
        m_ptr   = p.m_ptr;
        count   = p.count;
        p.m_ptr = nullptr;
        p.count = new int(1);
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
    T* m_ptr;
    // Invarient: @count will never be zero.
    int* count;
};

template <typename T, typename... Args> SharedPointer<T> make_shared(Args&&... args) {
    return SharedPointer<T>(new T(std::forward<Args>(args)...));
}

#endif