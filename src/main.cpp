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

using namespace std;

int main(int argc, const char * argv[]) {
    UniquePointer obj(new int(50));
    UniquePointer obj1(obj);
    *obj.ptr() = 30;
    int val = *obj1.ptr();
    cout << " Val is " << val << "\n";
    SharedPointer<Box> box1(new Box());
    cout << "count after box1 " << box1.count() <<"\n"; // Prints 1
    SharedPointer<Box> box2(box1); // calls copy constructor
    cout << "count after box2 " << box2.count() <<"\n"; // Prints 2
    return 0;
}
