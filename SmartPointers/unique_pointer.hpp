//
//  unique_pointer.hpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#ifndef unique_pointer_hpp
#define unique_pointer_hpp

#include <stdio.h>

template<typename P>
class UniquePointer
{

public: 

UniquePointer()
:m_ptr(nullptr)
{
}


~UniquePointer()
{
   // delete m_ptr;
   cleanup();
}


UniquePointer(P* ptr):m_ptr(ptr)
{
    
}

P* ptr()
{
    return this->m_ptr;
}

 void cleanup()
{
     if(this->m_ptr != nullptr)
     {
         delete this->m_ptr;
     }
}

P* operator->()
{
    return m_ptr;
}

P& operator*()
{
    return *m_ptr;
}

P* release()
{
    auto temp_ptr = m_ptr;
    cleanup();
    return temp_ptr;
}

void reset(P* new_ptr)
{
    auto temp_ptr = m_ptr;
    cleanup();
    m_ptr = new_ptr;
}

UniquePointer(const UniquePointer& ptr2)
{
}

P& operator=(const UniquePointer& ptr2)
{
}

UniquePointer<P> make_unique(P dataType)
{
    return unique_pointer<P>(new P());
}

private:
    P* m_ptr;
};



#endif /* unique_pointer_hpp */
