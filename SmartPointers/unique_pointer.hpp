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
private:
    P* m_ptr = nullptr;
public:
   UniquePointer();
    ~UniquePointer();
    UniquePointer(const UniquePointer& ptr2); // Copy Constructor
    P& operator=(const UniquePointer& ptr2) = delete;
    P* operator->();
    P& operator*();
    UniquePointer(P* ptr); 
    void cleanup();
    P* ptr();
    P* release();
    void reset(P* new_ptr);
    
    UniquePointer<P>& make_unique(P dataType);
    
};



#endif /* unique_pointer_hpp */
