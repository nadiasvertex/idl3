module;
#include <cctype>
#include <mutex>
#include <optional>
#include <ranges>
#include <string_view>
#include <tuple>
#include <vector>
export module cst:identifier;

import :position;

namespace cst {

/**
 * identifier_decl contains the identifier that was parsed out.
 */
export struct identifier_decl {
  std::string_view value;
};

/**
 * parse_identifier attempts to parse an identifier out of data.
 *
 * @param p the data position to start parsing from.
 * @return a view of the unconsumed data and a whitespace declaration on sucess,
 * or nothing on failure.
 */
export auto parse_identifier(position &p) -> std::optional<identifier_decl> {
  if (p.current_data.empty()) {
    return std::nullopt;
  }

  bool has_alpha=false;
  for (auto index = 0U; index < p.current_data.size(); ++index) {
    auto c = p.current_data[index];
    if (!has_alpha) {
      if (std::isalpha(c) || c == '_') {
        has_alpha=true;
        p.consume();
        continue;
      } else {
        return std::nullopt;
      }
    }

    if (std::isalnum(c) || c=='_') {
      p.consume();
      continue;
    }

    auto decl = identifier_decl{p.current_data.substr(0, index)};
    p.current_data.remove_prefix(decl.value.size());
    return decl;
  }

  auto decl = identifier_decl(p.current_data);
  p.current_data.remove_prefix(p.current_data.size());
  return decl;
}

} // namespace cst
