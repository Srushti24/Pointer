
# Find Google Test (or any other framework you're using)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test files
set(TEST_SOURCES
    unique_pointer.t.cpp
    shared_pointer.t.cpp
)

# Create executable for tests
add_executable(TestPointer ${TEST_SOURCES})

# Link Google Test libraries
target_link_libraries(TestPointer ${GTEST_LIBRARIES} pthread)

# Add tests
foreach(test_file ${TEST_SOURCES})
    get_filename_component(test_name ${test_file} NAME_WE)
    add_test(NAME ${test_name} COMMAND TestPointer)
endforeach()