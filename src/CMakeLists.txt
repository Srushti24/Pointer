ADD_EXECUTABLE(Pointer main.cpp)
include_directories("${CMAKE_SOURCE_DIR}/SmartPointers")
target_link_libraries(Pointer PUBLIC SmartPointers)
