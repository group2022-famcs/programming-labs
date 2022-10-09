project(04_arrays)

file(GLOB SRC_FILES *.cpp)
add_executable(test_04_arrays ${SRC_FILES})
target_link_libraries(test_04_arrays gtest_main gmock)

add_test(NAME test_04_arrays COMMAND test_04_arrays)
