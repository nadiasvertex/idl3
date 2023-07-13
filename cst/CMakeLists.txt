cmake_minimum_required(VERSION 3.26)
project(cst VERSION "${CMAKE_PROJECT_VERSION}" LANGUAGES CXX)

add_library(cst)
target_link_libraries(cst PRIVATE re2::re2)
target_sources(
        cst
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        cst.cppm
        position.cppm
        keyword.cppm
        scanner.cppm
        whitespace.cppm
)
