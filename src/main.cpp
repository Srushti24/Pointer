//
//  main.cpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#include <iostream>
#include <vector>
#include "Box.hpp"
#include "unique_pointer.hpp"
#include "shared_pointer.hpp"

int main(int argc, const char * argv[]) {
    // UniquePointer<int> ptr1;
    // UniquePointer<int>* ptr2 = new UniquePointer<int>();
    // UniquePointer<int> ptr3 = make_unique<int>();
     std::vector<UniquePointer<Box> > testArray;
    for (int i = 0; i < 3; ++i) {
        testArray.push_back(UniquePointer<Box>(new Box()));
    }
    

    //  for (auto& ptr : testArray) {
    //     std::cout << *ptr << "\n";
    // }
    // *ptr3 = 6;
    // std::cout << "value is \n" ;
    // std::cout << *ptr3  << "\n";



    // Shared Pointer Implementation

    SharedPointer<int> ptr1;
    auto ptr2 = make_shared<int>(10);
    std::cout <<  *ptr2 << "\n";
    return 0;
}

template<typename T, typename... Args>
UniquePointer<T> create_unique(typename... Args)
{
    return UniquePointer<T>(new T(std::forward<Args>(args)...));
}