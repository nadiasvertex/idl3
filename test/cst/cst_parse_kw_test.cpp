#include "catch2/benchmark/catch_benchmark.hpp"
#include "catch2/catch_test_macros.hpp"

import cst;

TEST_CASE("can scan keywords") {
  auto d1 = u8"protocol";
  auto r = cst::parse_keyword(d1);
  REQUIRE(r);
  const auto& [d2, decl] = *r;
  CHECK(decl.keyword == cst::keyword_type::protocol_kw);
}
