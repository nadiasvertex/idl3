prelude = """
#include "catch2/benchmark/catch_benchmark.hpp"
#include "catch2/catch_test_macros.hpp"

#include <string>

import cst;

TEST_CASE("can scan keywords") {
"""

tpl = """
SECTION("{kw}") {{
    std::string_view keyword{{"{kw}"}};
    cst::position p = {{ .current_data = keyword, .data = keyword}};
    auto r = cst::parse_keyword(p);
    REQUIRE(r);
    const auto &decl = *r;
    CHECK(decl.keyword == cst::keyword_type::{kw}_kw);
    CHECK(p.current_data.empty());
    CHECK(p.column == keyword.size()+1);
    CHECK(p.offset == keyword.size());
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
