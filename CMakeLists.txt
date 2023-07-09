cmake_minimum_required(VERSION 3.26)
project(idl3 VERSION "1.0.0" LANGUAGES CXX)
set(PRODUCT_FULL_NAME "Interface Description Language 3")
set(PROJECT_FULL_NAME "Interface Description Language 3")
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")

set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ABSL_PROPAGATE_CXX_STD ON)
set(ABSL_ENABLE_INSTALL ON)
set(BUILD_SHARED_LIBS OFF)
set(BUILD_TESTING OFF)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1
)

FetchContent_Declare(
        absl
        GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
        GIT_TAG        lts_2023_01_25
)

FetchContent_Declare(
        re2
        GIT_REPOSITORY https://github.com/google/re2.git
        GIT_TAG        2023-07-01
)

FetchContent_MakeAvailable(Catch2)
FetchContent_MakeAvailable(absl)
FetchContent_MakeAvailable(re2)

add_subdirectory(ast)
add_subdirectory(cst)
add_subdirectory(parser)
add_subdirectory(test)
