prelude = """
#include "catch2/benchmark/catch_benchmark.hpp"
#include "catch2/catch_test_macros.hpp"

#include <string>

import cst;

TEST_CASE("can scan keywords") {
"""

tpl = """
SECTION("{kw}") {{
    std::u8string_view keyword{{u8"{kw}"}};
    cst::position p = {{.data=keyword}};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::{kw}_kw);
    CHECK(p.data.empty());
    CHECK(p.column == keyword.size()+1);
}}
"""

postlude = """
}
"""

keywords = (
    "abstract",
    "const",
    "enum",
    "import",
    "message",
    "operation",
    "package",
    "protocol",
    "splice",
    "template",
    "type",
    "using",
    "with",
)

print(prelude)
for kw in keywords:
    print(tpl.format(kw=kw,kw_len=len(kw)))
print(postlude)
