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

using namespace std;

int main(int argc, const char * argv[]) {
    UniquePointer<int> ptr1;
    UniquePointer<int>* ptr2 = new UniquePointer<int>();
    UniquePointer<int> ptr3 = make_unique<int>();
    return 0;
}
