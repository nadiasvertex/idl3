project(cst_test VERSION "${CMAKE_PROJECT_VERSION}" LANGUAGES CXX)

add_executable(cst_tests cst_parse_kw_test.cpp cst_parse_ws_test.cpp cst_parse_identifier_test.cpp)
target_link_libraries(cst_tests PRIVATE cst Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(cst_tests)
