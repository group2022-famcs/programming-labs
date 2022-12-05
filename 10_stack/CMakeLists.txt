project(10_stack)

file(GLOB SRC_FILES *.cpp)
add_executable(test_10_stack ${SRC_FILES})
target_link_libraries(test_10_stack gtest_main gmock)

add_test(NAME test_10_stack COMMAND test_10_stack)
