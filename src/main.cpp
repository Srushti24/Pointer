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
//    std::vector<UniquePointer<int> > unique_ptrs;
//     for(size_t i=0; i< 7; i++)
//     {
//         unique_ptrs.push_back(make_unique<int>(i));
//     }
    *ptr3 = 6;
    // for(size_t i=0; i< 7; i++)
    // {
    //     std::cout <<  *unique_ptrs[i] << "\n";
    //}
    std::cout << "value is \n" ;
    std::cout << *ptr3  << "\n";

    return 0;
}
