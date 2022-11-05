project(07_matrix)

file(GLOB SRC_FILES *.cpp helpers/*.cpp)
add_executable(test_07_matrix ${SRC_FILES})
target_link_libraries(test_07_matrix gtest_main gmock)

add_test(NAME test_07_matrix COMMAND test_07_matrix)
