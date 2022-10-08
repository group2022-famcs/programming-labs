project(00_test)

file(GLOB SRC_FILES *.cpp)
add_executable(test_00_test ${SRC_FILES})
target_link_libraries(test_00_test gtest_main gmock)
