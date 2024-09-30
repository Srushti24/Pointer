//
//  main.cpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#include "Box.hpp"
#include "shared_pointer.hpp"
#include "unique_pointer.hpp"
#include <iostream>
#include <vector>
#include <cassert>



void testUniquePointer()
{
     UniquePointer<int> uniquePointer = make_unique<int>(5);
     UniquePointer<int> uniquePointerOne = make_unique<int>(10);
     assert(*uniquePointer == 5);
     assert(*uniquePointerOne == 10);
     uniquePointer = (std::move(uniquePointerOne));
     assert(*uniquePointer == 10);

}

void testUniqueArrayPtr()
{
    std::vector<UniquePointer<int>> intVectors;
    for(size_t i =0; i< 5 ; i++)
    {
        intVectors.push_back(make_unique<int>(i));
    }
    std::cout << "intVector size is " << intVectors.size() << "\n";
}


void testSharedPointer()
{
    SharedPointer<int> shared_pointer = make_shared<int>(5);
     SharedPointer<int> shared_pointer_one = make_shared<int>(10);
     assert(*shared_pointer == 5);
     assert(*shared_pointer_one == 10);
     shared_pointer = (std::move(shared_pointer_one));
     assert(*shared_pointer == 10);
}


void testUniquePointerCreation()
{
    SharedPointer<int> shared_pointer = make_shared<int>(5);
     SharedPointer<int> shared_pointer_one = make_shared<int>(10);
     assert(*shared_pointer == 5);
     assert(*shared_pointer_one == 10);
     shared_pointer = (std::move(shared_pointer_one));
     assert(*shared_pointer == 10);
}

void testUniquePointerStruct()
{
    int constructionCount = 0;
    int destructionCount = 0;

    struct S{
        S(int& constructionCount, int& destructionCount): constructionCount(constructionCount), destructionCount(destructionCount)
        {
            std::cout << "constructionCount \n" ;
            constructionCount++;
        }
        ~S(){
            std::cout << "destructionCount \n" ;
            destructionCount++;
        }
        int constructionCount;
        int destructionCount; 
    };

    std::vector<UniquePointer<S>> vectorS;
    for(size_t i =0; i< 5; i++)
    {
        vectorS.push_back(make_unique<S>(constructionCount, destructionCount));
    }
    assert(constructionCount == 5);
    assert( destructionCount == 0);
}

template <typename T, typename... Args> 
UniquePointer<T> createUniquePtr(Args&&... args)
{
    return make_unique<T>(std::forward<Args>(args)...);
}

UniquePointer<int> createIntPtr()
{
    UniquePointer<int> temp;
    return temp;
}

template<typename T>
void forTesting(UniquePointer<T> args)
{
    std::cout << "value is " << *args << "\n";
}

int main(int argc, const char* argv[]) {
   testUniquePointer();
   testSharedPointer();
   testUniquePointerCreation();
   testUniquePointerStruct();
   UniquePointer<int> temp = createUniquePtr<int>(5);
   std::cout << "here \n";
   assert(*temp == 5);
    forTesting(createUniquePtr<int>(10));
  UniquePointer<int> temp = createIntPtr();
  testUniqueArrayPtr();
    return 0;
}





