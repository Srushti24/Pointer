//
//  unique_pointer.cpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#include "unique_pointer.hpp"


template<typename P>
UniquePointer<P>::UniquePointer():m_ptr(nullptr)
{
}

template<typename P>
UniquePointer<P>::~UniquePointer()
{
   cleanup();
}

template<typename P>
UniquePointer<P>::UniquePointer(P* ptr):m_ptr(ptr)
{
    
}

template<typename P>
P* UniquePointer<P>::ptr()
{
    return this->m_ptr;
}

template<typename P>
 void UniquePointer<P>::cleanup()
{
     if(nullptr != this->m_ptr)
     {
         delete this->m_ptr;
     }
}

template<typename P>
P* UniquePointer<P>::operator->()
{
    return m_ptr;
}

template<typename P>
P& UniquePointer<P>::operator*()
{
    return *m_ptr;
}


template<typename P>
P* UniquePointer<P>::release()
{
    auto temp_ptr = m_ptr;
    cleanup();
    return temp_ptr;
}

template<typename P>
void UniquePointer<P>::reset(P* new_ptr)
{
    auto temp_ptr = m_ptr;
    cleanup();
    m_ptr = new_ptr;
}


template<typename P>
UniquePointer<P>:: UniquePointer(const UniquePointer& ptr2)
{
}

template<typename P>
UniquePointer<P>& UniquePointer<P>:: make_unique(P dataType)
{
    return unique_pointer<P>(new P());
}




