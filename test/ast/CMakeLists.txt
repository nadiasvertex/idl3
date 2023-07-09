project(ast_test VERSION "${CMAKE_PROJECT_VERSION}" LANGUAGES CXX)

add_executable(ast_tests ast_package_test.cpp ast_using_test.cpp)
target_link_libraries(ast_tests PRIVATE ast Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(ast_tests)
