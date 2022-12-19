project(12_stl)

file(GLOB SRC_FILES *.cpp)
add_executable(test_12_stl ${SRC_FILES})
target_link_libraries(test_12_stl gtest_main gmock)

add_test(NAME test_12_stl COMMAND test_12_stl)
