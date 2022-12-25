project(12_stl)

file(GLOB SRC_FILES *.cpp)
add_executable(test_12_stl ${SRC_FILES})

add_test(NAME test_12_stl COMMAND test_12_stl)
