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
            : constructionCount_(constructionCount), destructionCount_(destructionCount) {
            constructionCount_++;
        }
        ~S() { destructionCount_++; }
        int& constructionCount_;
        int& destructionCount_;
    };
    {
        std::vector<UniquePointer<S>> vectorS;
        for (size_t i = 0; i < 5; i++) {
            vectorS.push_back(make_unique<S>(constructionCount, destructionCount));
        }
    }
    assert(constructionCount == 5);
    assert(destructionCount == 5);
}

int main(int argc, const char* argv[]) {
    testSharedPtrWithStruct();
    testUniquePointerStruct();
    testSharedPointerWithContext();
    testMoveOpt();
    testCopyAssignOpWithObj();
    testCopyAssignNoObj();
    testCopyCrtNoObj();
    testCopyCrtObj();
    testMoveCrt();
    testParamCrtWithObj();
    testParamCrtWithNullObj();
    testMultipleCrt();
    testMultipleNullCrt();
    testMultipleContextDelete();
    testChangingObjectValues();
    return 0;
}
