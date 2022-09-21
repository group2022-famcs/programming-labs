project(adviser)

add_library(adviser adviser.cpp)

add_executable(test_adviser tests.cpp)
target_link_libraries(test_adviser gtest_main adviser)

add_test(NAME test_adviser COMMAND test_adviser)
