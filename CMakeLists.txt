cmake_minimum_required(VERSION 3.23)

project(playground-for-private-tests)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/aa2e91fd6918519dafa3bee4aa706d04857e7d06.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(oracle)
add_subdirectory(adviser)
