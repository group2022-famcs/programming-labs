project(06_big_integer)

file(GLOB SRC_FILES *.cpp)
add_executable(test_06_big_integer ${SRC_FILES})
target_link_libraries(test_06_big_integer gtest_main gmock)

add_test(NAME test_06_big_integer COMMAND test_06_big_integer)
