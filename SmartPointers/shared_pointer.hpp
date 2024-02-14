//
//  shared_pointer.hpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#ifndef shared_pointer_hpp
#define shared_pointer_hpp

#include <stdio.h>
template<class T>
class SharedPointer
{
private:
    T* m_ptr;
    unsigned int* m_count;
public:
     SharedPointer():m_ptr(nullptr), m_count(new unsigned int(0))
    {
        
    }

    ~SharedPointer(){
        cleanup();
        
    }

    SharedPointer(T * ptr) : m_ptr(ptr), m_count(new unsigned int(1))
        {
        }

    SharedPointer(const SharedPointer& sharedPtr){ // Copy constructor
        this->m_ptr = sharedPtr.m_ptr;
        this->m_count = sharedPtr.m_count;
        if(nullptr != sharedPtr.m_ptr)
        {
            (*this->m_count)++;
        }
        
    }
    
    SharedPointer& operator=(const SharedPointer& sharedPtr)
    {
        this->m_ptr = sharedPtr.m_ptr;
        this->m_count = sharedPtr.m_count;
        if(nullptr != sharedPtr.m_ptr)
        {
            (*this->m_count)++;
        }
    }
    
    T* operator->() const
    {
        return this->m_ptr;
    }
    

     void cleanup(){
            (*m_count)--;
            if (*m_count == 0)
            {
                if (nullptr != m_ptr)
                    delete m_ptr;
                delete m_count;
            }
        }
    
    int count()
    {
        return *m_count;
    }


    
};

#endif /* shared_pointer_hpp */
