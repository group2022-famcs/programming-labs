project(08_population)

file(GLOB SRC_FILES *.cpp helpers/*.cpp)
add_executable(test_08_population ${SRC_FILES})
target_link_libraries(test_08_population gtest_main gmock)

add_test(NAME test_08_population COMMAND test_08_population)
