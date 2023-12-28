//
//  unique_pointer.hpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#ifndef unique_pointer_hpp
#define unique_pointer_hpp

#include <stdio.h>

class UniquePointer
{
private:
    int* m_ptr = nullptr;
public:
   UniquePointer();
    ~UniquePointer();
    UniquePointer(const UniquePointer& ptr2);
    UniquePointer(int* ptr);
    void cleanup();
    int* ptr();
    
};



#endif /* unique_pointer_hpp */
