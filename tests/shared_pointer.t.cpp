#include "shared_pointer.hpp"
#include <gtest/gtest.h>
#include <algorithm>

TEST(SharedPointer, creatingNew) {
     SharedPointer<int> shared_pointer = make_shared<int>(5);
     SharedPointer<int> shared_pointer_one = make_shared<int>(10);
     EXPECT_EQ(*shared_pointer, 5);
     EXPECT_EQ(*shared_pointer_one, 10);
     shared_pointer = (std::move(shared_pointer_one));
     EXPECT_EQ(*shared_pointer, 10);
}
