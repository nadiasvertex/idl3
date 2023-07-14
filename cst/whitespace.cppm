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
  std::string_view value;
};

/**
 * parse_whitespace attempts to parse a whitespace out of data.
 *
 * @param data the data stream to parse
 * @return a view of the unconsumed data and a whitespace declaration on sucess,
 * or nothing on failure.
 */
export auto parse_whitespace(position &p) -> std::optional<whitespace_decl> {
  for (auto index = 0U; index < p.current_data.size(); ++index) {
    switch (p.current_data[index]) {
    case ' ':
    case '\t':
    case '\r':
      p.offset++;
      p.column++;
      break;
    case '\n':
      p.offset++;
      p.line++;
      p.column = 1;
      break;
    default:
      if (index == 0) {
        return std::nullopt;
      } else {
        auto decl = whitespace_decl{p.current_data.substr(0, index)};
        p.current_data.remove_prefix(index);
        return decl;
      }
    }
  }

  auto decl = whitespace_decl(p.current_data);
  p.current_data.remove_prefix(p.current_data.size());
  return decl;
}

} // namespace cst
