//
//  main.cpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#include "Box.hpp"
#include "my_pointer.hpp"
#include "shared_pointer.hpp"
#include "shared_pointer_v2.hpp"
#include "unique_pointer.hpp"
#include <cassert>
#include <iostream>
#include <vector>

void testUniquePointer() {
    UniquePointer<int> uniquePointer    = make_unique<int>(5);
    UniquePointer<int> uniquePointerOne = make_unique<int>(10);
    assert(*uniquePointer == 5);
    assert(*uniquePointerOne == 10);
    uniquePointer = (std::move(uniquePointerOne));
    assert(*uniquePointer == 10);
}

void testUniqueArrayPtr() {
    std::vector<UniquePointer<int>> intVectors;
    for (size_t i = 0; i < 5; i++) {
        intVectors.push_back(make_unique<int>(i));
    }
    std::cout << "intVector size is " << intVectors.size() << "\n";
}

void testSharedPointer() {
    SharedPointer<int> shared_pointer     = make_shared<int>(5);
    SharedPointer<int> shared_pointer_one = make_shared<int>(10);
    assert(*shared_pointer == 5);
    assert(*shared_pointer_one == 10);
    shared_pointer = std::move(shared_pointer_one);
    assert(*shared_pointer == 10);
}

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
            std::cout << "destructionCount \n";
            destructionCount++;
        }
        int constructionCount;
        int destructionCount;
    };

    std::vector<UniquePointer<S>> vectorS;
    for (size_t i = 0; i < 5; i++) {
        vectorS.push_back(make_unique<S>(constructionCount, destructionCount));
    }
    assert(constructionCount == 5);
    assert(destructionCount == 0);
}

template <typename T, typename... Args> UniquePointer<T> createUniquePtr(Args&&... args) {
    return make_unique<T>(std::forward<Args>(args)...);
}

UniquePointer<int> createIntPtr() {
    UniquePointer<int> temp;
    return temp;
}

template <typename T> void forTesting(UniquePointer<T> args) { std::cout << "value is " << *args << "\n"; }

void testForTesting() {
    SharedPointer<int> temp1;
    int*               temp = new int(5);
    SharedPointer<int> temp2(temp);
}

void testSharedPointerTwo() {
    SharedPointer<int> temp;
    {
        auto temp2 = SharedPointer<int>(new int{5});
        temp       = temp2;
    }
    std::cout << "temp value is " << *temp << std::endl;
}

void testSharedV2One() {
    SharedPointerV2<int> temp;
    {
        auto temp1 = SharedPointerV2<int>(new int{5});
        temp       = temp1;
    }
    assert(*temp == 5);
}

void testSharedV2Two() { // Testing move operator
    SharedPointerV2<int> s1(new int{6});
    SharedPointerV2<int> s2 = std::move(s1);
    assert(*s2 == 6);
}

void testSharedV2Three() { // Testing copy Assignment operator when an object is passed
    SharedPointerV2<Box> s1(new Box{6});
    auto                 s2 = s1;
    assert(s1->m_len == 6);
    assert(s2.getCount() == 2);
}

void testSharedV2Four() { // Testing copy Assignment when no object is passed
    SharedPointerV2<Box> s1;
    auto                 s2 = s1;
    assert(s1.getCount() == 0);
}

void testSharedV2Five() { // Testing copy constructor when no object is passed
    SharedPointerV2<Box> s1;
    SharedPointerV2<Box> s2(s1);
    assert(s1.getCount() == 0);
}

void testSharedV2Six() { // Testing copy constructor when object is passed
    SharedPointerV2<Box> s1(new Box(7));
    assert(s1.getCount() == 1);
    SharedPointerV2<Box> s2(s1);
    assert(s2.getCount() == 2);
}

void testSharedPointerV2Seven() { // Testing move constructor
    SharedPointerV2<Box> s1(new Box(7));
    assert(s1->m_len == 7);
    assert(s1.getCount() == 1);
    SharedPointerV2<Box> s2(std::move(s1));
    assert(s2->m_len == 7);
    assert(s1.getCount() == 0);
}

void testSharedPointerV2Eight() { // Testing param constructor with an object passed
    SharedPointerV2<Box> s1(new Box(7));
    assert(s1->m_len == 7);
    assert(s1.getCount() == 1);
}

void testSharedPointerV2Nine() { // Testing param constructor with a null passed
    SharedPointerV2<int> s1(new int{});
    // assert(s1.getCount() == 0);
}

void testSharedPointerV2Ten() { // Testing  constructor
    SharedPointerV2<int> s1;
    assert(s1.getCount() == 0);
}

void testSharedPointerV2Eleven() { // Testing  constructor
    SharedPointerV2<int> s1(new int{5});
    assert(*s1 == 5);
    assert(s1.getCount() == 1);
}

int main(int argc, const char* argv[]) {
    testSharedV2One();
    testSharedV2Two();
    testSharedV2Three();
    testSharedV2Four();
    testSharedV2Five();
    testSharedV2Six();
    testSharedPointerV2Seven();
    testSharedPointerV2Eight();
    testSharedPointerV2Ten();
    testSharedPointerV2Eleven();
    return 0;
}
