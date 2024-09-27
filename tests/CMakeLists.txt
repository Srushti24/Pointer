# Add test files
set(TEST_FILES
unique_pointer.t.cpp
shared_pointer.t.cpp
)
# Create executable for tests
add_executable(run_tests ${TEST_FILES})

# Link Google Test to your test executable
target_link_libraries(run_tests gtest gtest_main)

# Add a test for CMake
add_test(NAME MyTests COMMAND run_tests)
