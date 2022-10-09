cmake_minimum_required(VERSION 3.23)

project(programming-labs)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/aa2e91fd6918519dafa3bee4aa706d04857e7d06.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()


include(cmake/ClangTidyCheck.cmake)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror")

add_subdirectory(00_test)
add_subdirectory(lab04)
