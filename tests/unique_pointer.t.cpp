#include "unique_pointer.hpp"
#include <gtest/gtest.h>
#include <algorithm>

TEST(UniquePointer, creatingNew) {
     UniquePointer<int> uniquePointer = make_unique<int>(5);
     UniquePointer<int> uniquePointerOne = make_unique<int>(10);
     EXPECT_EQ(*uniquePointer, 5);
     EXPECT_EQ(*uniquePointerOne, 10);
     uniquePointer = (std::move(uniquePointerOne));
     EXPECT_EQ(*uniquePointer, 10);
}


TEST(UniquePointer, creatingUniquePointerArray) {
    std::vector<UniquePointer<int>> uniquePointerArray;
    for(size_t i =0; i< 10; i++)
    {
        uniquePointerArray.push_back(make_unique<int>(i));
    }
     std::cout<< "Unique Pointer size is " << uniquePointerArray.size() << "\n";
    EXPECT_EQ(uniquePointerArray.size(), 10);
}