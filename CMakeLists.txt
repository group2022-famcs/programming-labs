cmake_minimum_required(VERSION 3.22)

project(programming-labs)

include(cmake/BuildConfig.cmake)

include(FetchContent)
# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/aa2e91fd6918519dafa3bee4aa706d04857e7d06.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

include(cmake/ClangTidyCheck.cmake)

include_directories(tools/util)

add_subdirectory(00_test)
add_subdirectory(04_arrays)
add_subdirectory(06_big_integer)
add_subdirectory(07_matrix)
add_subdirectory(08_population)
add_subdirectory(09_big_float)
add_subdirectory(10_stack)
