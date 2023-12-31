#include "catch2/benchmark/catch_benchmark.hpp"
#include "catch2/catch_test_macros.hpp"

#include <string>

import cst;

TEST_CASE("can scan whitespace") {

  SECTION("spaces only") {
    std::string_view data{"     "};
    cst::position p = {.current_data = data, .data = data};
    auto r = cst::parse_whitespace(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.value == data);
    CHECK(p.current_data.empty());
    CHECK(p.column == data.size() + 1);
  }

  SECTION("spaces and tabs") {
    std::string_view data{" \t \t  "};
    cst::position p = {.current_data = data, .data = data};
    auto r = cst::parse_whitespace(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.value == data);
    CHECK(p.current_data.empty());
    CHECK(p.column == data.size() + 1);
  }

  SECTION("spaces, tabs, and carriage returns") {
    std::string_view data{" \t \t \r \r "};
    cst::position p = {.current_data = data, .data = data};
    auto r = cst::parse_whitespace(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.value == data);
    CHECK(p.current_data.empty());
    CHECK(p.column == data.size() + 1);
  }

  SECTION("spaces, tabs, carriage returns, and newlines") {
    std::string_view data{" \t \n \t \r \n \r "};
    cst::position p = {.current_data = data, .data = data};
    auto r = cst::parse_whitespace(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.value == data);
    CHECK(p.current_data.empty());
    CHECK(p.column == 4);
    CHECK(p.line == 3);
    CHECK(p.offset == p.data.size());
  }
}
