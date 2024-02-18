//
//  unique_pointer.cpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#include "unique_pointer.hpp"



UniquePointer::UniquePointer():m_ptr(nullptr)
{
}


UniquePointer::~UniquePointer()
{
   // cleanup();
}


UniquePointer::UniquePointer(int* ptr):m_ptr(ptr)
{
    
}


UniquePointer::UniquePointer(const UniquePointer& ptr2) //Copy assignment operator
{
    this->m_ptr = ptr2.m_ptr;
}

int* UniquePointer::ptr()
{
    return this->m_ptr;
}


 void UniquePointer::cleanup()
{
     if(nullptr != this->m_ptr)
     {
         delete this->m_ptr;
     }
}





