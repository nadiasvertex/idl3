module;
#include <mutex>
#include <optional>
#include <ranges>
#include <string_view>
#include <tuple>
#include <vector>
export module cst:whitespace;

import :position;

namespace cst {

/**
 * whitespace_decl contains
 */
export struct whitespace_decl {
  std::u8string_view value;
};

/**
 * parse_whitespace attempts to parse a whitespace out of data.
 *
 * @param data the data stream to parse
 * @return a view of the unconsumed data and a whitespace declaration on sucess,
 * or nothing on failure.
 */
export auto parse_whitespace(position &p) -> std::optional<whitespace_decl> {
  for (auto index = 0U; index < p.data.size(); ++index) {
    switch (p.data[index]) {
    case ' ':
    case '\t':
    case '\r':
      p.column++;
      break;
    case '\n':
      p.line++;
      p.column = 1;
      break;
    default:
      auto decl = whitespace_decl{p.data.substr(0, index)};
      p.data.remove_prefix(index);
      return decl;
    }
  }

  auto decl = whitespace_decl(p.data);
  p.data.remove_prefix(p.data.size());
  return decl;
}

} // namespace cst
