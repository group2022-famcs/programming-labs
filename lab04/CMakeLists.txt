project(lab04)

add_library(solutions task1.cpp task2.cpp task3.cpp task4.cpp task5.cpp task6.cpp task7.cpp task8.cpp)

add_executable(test_lab04 public_test.cpp)
target_link_libraries(test_lab04 gtest_main solutions)

add_test(NAME test_lab04 COMMAND test_lab04)
