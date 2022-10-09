project(lab04)

file(GLOB SRC_FILES *.cpp)
add_executable(test_lab04 ${SRC_FILES})
target_link_libraries(test_lab04 gtest_main gmock)

add_test(NAME test_lab04 COMMAND test_lab04)
