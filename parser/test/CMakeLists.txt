project(parser_test VERSION "${CMAKE_PROJECT_VERSION}" LANGUAGES CXX)

add_executable(parser_tests parser_package_test.cpp)
target_link_libraries(parser_tests PRIVATE parser Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(parser_tests)
