project(09_big_float)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC_FILES *.cpp helpers/*.cpp)
add_executable(test_09_big_float ${SRC_FILES})
target_link_libraries(test_09_big_float gtest_main gmock)

add_test(NAME test_09_big_float COMMAND test_09_big_float)
