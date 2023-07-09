cmake_minimum_required(VERSION 3.26)
project(ast VERSION "${CMAKE_PROJECT_VERSION}" LANGUAGES CXX)

add_library(ast)
target_sources(
        ast
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        ast.cppm
        data_type.cppm
        decl.cppm
        decorated_decl.cppm
        decorator_decl.cppm
        field_decl.cppm
        operation_decl.cppm
        package_decl.cppm
        primitive_decl.cppm
        protocol_decl.cppm
        type_descriptor.cppm
        type_info.cppm
        using_decl.cppm
)
