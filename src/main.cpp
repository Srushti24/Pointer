//
//  main.cpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#include <iostream>
#include <vector>
#include "Box.hpp"
#include "shared_pointer.hpp"
#include "unique_pointer.hpp"

int main(int argc, const char * argv[]) {
    UniquePointer<int> ptr1;
    UniquePointer<int>* ptr2 = new UniquePointer<int>();
    UniquePointer<int> ptr3 = make_unique<int>();
    std::vector<UniquePointer<int> > testArray;
    for (int i = 0; i < 3; ++i) {
        testArray.push_back(UniquePointer<int>(new int(i)));
    }

     for (auto& ptr : testArray) {
        std::cout << *ptr << "\n";
    }
    *ptr3 = 6;
    std::cout << "value is \n" ;
    std::cout << *ptr3  << "\n";

    return 0;
}
