
#include "catch2/benchmark/catch_benchmark.hpp"
#include "catch2/catch_test_macros.hpp"

#include <string>

import cst;

TEST_CASE("can scan keywords") {

  SECTION("abstract") {
    std::string_view keyword{"abstract"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::abstract_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }

  SECTION("const") {
    std::string_view keyword{"const"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::const_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }

  SECTION("enum") {
    std::string_view keyword{"enum"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::enum_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }

  SECTION("import") {
    std::string_view keyword{"import"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::import_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }

  SECTION("message") {
    std::string_view keyword{"message"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::message_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }

  SECTION("operation") {
    std::string_view keyword{"operation"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::operation_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }

  SECTION("package") {
    std::string_view keyword{"package"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::package_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }

  SECTION("protocol") {
    std::string_view keyword{"protocol"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::protocol_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }

  SECTION("splice") {
    std::string_view keyword{"splice"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::splice_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }

  SECTION("template") {
    std::string_view keyword{"template"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::template_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }

  SECTION("type") {
    std::string_view keyword{"type"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::type_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }

  SECTION("using") {
    std::string_view keyword{"using"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::using_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }

  SECTION("with") {
    std::string_view keyword{"with"};
    cst::position p = {.current_data = keyword, .data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::with_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size() + 1);
    CHECK(p.offset == keyword.size());
  }
}
