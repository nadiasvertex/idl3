#include "catch2/benchmark/catch_benchmark.hpp"
#include "catch2/catch_test_macros.hpp"

#include <string>

import cst;

TEST_CASE("can scan whitespace") {

  SECTION("spaces only") {
    std::u8string_view data{u8"     "};
    cst::position p = {.data = data};
    auto r = cst::parse_whitespace(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.value == data);
    CHECK(p.data.empty());
    CHECK(p.column == data.size() + 1);
  }

  SECTION("spaces and tabs") {
    std::u8string_view data{u8" \t \t  "};
    cst::position p = {.data = data};
    auto r = cst::parse_whitespace(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.value == data);
    CHECK(p.data.empty());
    CHECK(p.column == data.size() + 1);
  }

  SECTION("spaces, tabs, and carriage returns") {
    std::u8string_view data{u8" \t \t \r \r "};
    cst::position p = {.data = data};
    auto r = cst::parse_whitespace(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.value == data);
    CHECK(p.data.empty());
    CHECK(p.column == data.size() + 1);
  }

  SECTION("spaces, tabs, carriage returns, and newlines") {
    std::u8string_view data{u8" \t \n \t \r \n \r "};
    cst::position p = {.data = data};
    auto r = cst::parse_whitespace(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.value == data);
    CHECK(p.data.empty());
    CHECK(p.column == 4);
    CHECK(p.line == 3);
  }
}
