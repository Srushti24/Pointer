ADD_EXECUTABLE(Pointer main.cpp)
include_directories("${CMAKE_SOURCE_DIR}/SmartPointers")
target_link_libraries(Pointer PUBLIC SmartPointers)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(Pointer PRIVATE -fsanitize=address -g)
    target_link_libraries(Pointer PRIVATE -fsanitize=address)
endif()