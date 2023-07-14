#include "catch2/benchmark/catch_benchmark.hpp"
#include "catch2/catch_test_macros.hpp"

#include <string>

import cst;

TEST_CASE("can scan identifier") {

  SECTION("alpha only") {
    std::string_view data{"abcde"};
    cst::position p = {.current_data = data, .data = data};
    auto r = cst::parse_identifier(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.value == data);
    CHECK(p.current_data.empty());
    CHECK(p.column == data.size() + 1);
  }

  SECTION("alphanumeric") {
    std::string_view data{"abcdefg12332"};
    cst::position p = {.current_data = data, .data = data};
    auto r = cst::parse_identifier(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.value == data);
    CHECK(p.current_data.empty());
    CHECK(p.column == data.size() + 1);
  }

  SECTION("all legal character kinds") {
    std::string_view data{"abdf_2321"};
    cst::position p = {.current_data = data, .data = data};
    auto r = cst::parse_identifier(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.value == data);
    CHECK(p.current_data.empty());
    CHECK(p.column == data.size() + 1);
  }

  SECTION("can start with underscore") {
    std::string_view data{"_abdfghij0987654321"};
    cst::position p = {.current_data = data, .data = data};
    auto r = cst::parse_identifier(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.value == data);
    CHECK(p.current_data.empty());
    CHECK(p.column == data.size() + 1);
  }

  SECTION("cannot start with number") {
    std::string_view data{"1abcd"};
    cst::position p = {.current_data = data, .data = data};
    auto r = cst::parse_identifier(p);
    REQUIRE_FALSE(r);
    CHECK(p.column==1);
    CHECK(p.offset==0);
  }

}
