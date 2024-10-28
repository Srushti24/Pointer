//
//  main.cpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#include "Box.hpp"
#include "my_pointer.hpp"
#include "shared_pointer.hpp"
#include "shared_pointer_v2_test.cpp"
#include "unique_pointer.hpp"
#include <cassert>
#include <iostream>
#include <vector>

void testUniquePointerStruct() {
    int constructionCount = 0;
    int destructionCount  = 0;
    struct S {
        S(int& constructionCount, int& destructionCount)
            : constructionCount(constructionCount), destructionCount(destructionCount) {
            std::cout << "constructionCount \n";
            constructionCount++;
        }
        ~S() {
            std::cout << "destructionCount before = " << destructionCount << std::endl;
            destructionCount++;
            std::cout << "destructionCount after = " << destructionCount << std::endl;
        }
        int constructionCount;
        int destructionCount;
    };
    {
        std::vector<UniquePointer<S>> vectorS;
        for (size_t i = 0; i < 5; i++) {
            vectorS.push_back(make_unique<S>(constructionCount, destructionCount));
        }
        for (size_t i = 0; i < 5; i++) {

            std::cout <<  vectorS[i]->constructionCount << std::endl;
        }
        vectorS.pop_back();
        std::cout << "destructionCount after pop  = " << destructionCount << std::endl;
        std::cout << "constructionCount after pop  = " << constructionCount << std::endl;
    }
    std::cout << "destructionCount = " << destructionCount << std::endl;
    std::cout << "constructionCount = " << constructionCount << std::endl;
    assert(constructionCount == 5);
    assert(destructionCount == 0);
    std::cout << "done with assertion" << std::endl;
}

int main(int argc, const char* argv[]) {
    //testUniquePointerStruct();
    testMultipleCrt();
    return 0;
}
