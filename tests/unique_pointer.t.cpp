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
