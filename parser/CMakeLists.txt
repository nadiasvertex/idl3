cmake_minimum_required(VERSION 3.26)
project(parser VERSION "${CMAKE_PROJECT_VERSION}" LANGUAGES CXX)

add_library(parser )
target_sources(parser
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        parser.cppm
        package.cppm
        using.cppm
        )

