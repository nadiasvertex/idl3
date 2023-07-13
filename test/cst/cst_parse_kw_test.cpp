#include "catch2/benchmark/catch_benchmark.hpp"
#include "catch2/catch_test_macros.hpp"

#include <string>

import cst;

TEST_CASE("can scan keywords") {

  SECTION("abstract") {
    std::u8string_view keyword{u8"abstract"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::abstract_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }

  SECTION("const") {
    std::u8string_view keyword{u8"const"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::const_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }

  SECTION("enum") {
    std::u8string_view keyword{u8"enum"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::enum_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }

  SECTION("import") {
    std::u8string_view keyword{u8"import"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::import_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }

  SECTION("message") {
    std::u8string_view keyword{u8"message"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::message_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }

  SECTION("operation") {
    std::u8string_view keyword{u8"operation"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::operation_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }

  SECTION("package") {
    std::u8string_view keyword{u8"package"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::package_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }

  SECTION("protocol") {
    std::u8string_view keyword{u8"protocol"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::protocol_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }

  SECTION("splice") {
    std::u8string_view keyword{u8"splice"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::splice_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }

  SECTION("template") {
    std::u8string_view keyword{u8"template"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::template_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }

  SECTION("type") {
    std::u8string_view keyword{u8"type"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::type_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }

  SECTION("using") {
    std::u8string_view keyword{u8"using"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::using_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }

  SECTION("with") {
    std::u8string_view keyword{u8"with"};
    cst::position p = {.data = keyword};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::with_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size() + 1);
  }
}
