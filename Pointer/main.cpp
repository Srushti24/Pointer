//
//  main.cpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#include <iostream>
#include "Box.hpp"
#include "shared_pointer.hpp"
#include "unique_pointer.hpp"

int main(int argc, const char * argv[]) {
    SharedPointer<Box> box;
    UniquePointer obj(new int(50));
    UniquePointer obj1(obj);
    *obj.ptr() = 30;
    int val = *obj1.ptr();
    std::cout << "val is" << val; //30
    std::cout << "count after box " << box.count() ;
    SharedPointer<Box> box1(new Box());
    std::cout << "count after box1 " << box1.count() ; // Prints 1
    SharedPointer<Box> box2(box1); // calls copy constructor
    std::cout << "count after box2 " << box2.count() ; // Prints 2
    return 0;
}
