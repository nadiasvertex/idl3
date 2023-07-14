module;
#include <mutex>
#include <optional>
#include <ranges>
#include <string_view>
#include <tuple>
#include <vector>
export module cst:keyword;

import :position;

namespace cst {

export enum class keyword_type {
  abstract_kw,
  const_kw,
  enum_kw,
  import_kw,
  message_kw,
  operation_kw,
  package_kw,
  protocol_kw,
  splice_kw,
  template_kw,
  type_kw,
  using_kw,
  with_kw
};

std::vector<std::tuple<std::string_view, keyword_type>> kw_map = {
    {"abstract", keyword_type::abstract_kw},
    {"const", keyword_type::const_kw},
    {"enum", keyword_type::enum_kw},
    {"import", keyword_type::import_kw},
    {"message", keyword_type::message_kw},
    {"operation", keyword_type::operation_kw},
    {"package", keyword_type::package_kw},
    {"protocol", keyword_type::protocol_kw},
    {"splice", keyword_type::splice_kw},
    {"template", keyword_type::template_kw},
    {"type", keyword_type::type_kw},
    {"using", keyword_type::using_kw},
    {"with", keyword_type::with_kw}};

struct kw_pattern_state {
  std::optional<std::string::value_type> value;
  std::optional<keyword_type> keyword;
  std::vector<kw_pattern_state> next_states;
};

/**
 * kw_pattern holds the start states for all patterns and functions to mutate
 * and query the pattern states.
 */
struct kw_pattern {
  using size_type = std::string_view::size_type;
  std::vector<kw_pattern_state> patterns;

  /**
   * add_alternative adds a pattern into the pattern state tree, and assigns
   * it to a keyword enum.
   *
   * @param pattern the pattern to add
   * @param kw the keyword end state
   */
  void add_alternative(std::string_view pattern, keyword_type kw) {
    auto *ps = &patterns;
    for (const auto &c : pattern) {
      auto pos = std::ranges::find_if(*ps, [&c](kw_pattern_state &state) {
        return state.value.has_value() && state.value == c;
      });

      // If 'c' doesn't exist in the state vector, add it and move down that
      // subtree.
      if (pos == ps->end()) {
        ps->emplace_back(c);
        ps = &(ps->back().next_states);
      } else {
        ps = &(pos->next_states);
      }
    }

    ps->emplace_back(std::nullopt, kw);
  }

  /**
   * match tries to match 'data' in the pattern tree and if successful indicates
   * how much data was consumed and which keyword was found. On a failed match
   * it returns nothing. This function matches all options in parallel.
   *
   * @param data the data to search.
   * @return a count of consumed data and the keyword found on success, or
   * nothing.
   */
  [[nodiscard]] auto match(std::string_view data) const
      -> std::optional<std::tuple<size_type, keyword_type>> {
    bool match_failed = false;
    const auto *ps = &patterns;
    std::vector<std::tuple<size_type, keyword_type>> matches;
    for (std::string_view::size_type index = 0; index < data.size(); ++index) {
      auto pos = std::ranges::find_if(
          *ps, [c = data[index]](const kw_pattern_state &state) {
            return state.value.has_value() && state.value == c;
          });

      if (pos == ps->end()) {
        match_failed = true;
        break;
      } else {
        if (pos->keyword) {
          matches.emplace_back(index, *pos->keyword);
        }
        ps = &(pos->next_states);
      }
    }

    // If we reached the end of the input without failing, we need to see if
    // there is an end state in the pattern tree at this node.
    if (!match_failed) {
      if (auto pos = std::ranges::find_if(
          *ps, [](const kw_pattern_state &state) {
            return !state.value.has_value() && state.keyword.has_value();
          }); pos!=ps->end()) {
        matches.emplace_back(data.size(), pos->keyword.value());
      }
    }

    // Determine if we found a match.
    if (!matches.empty()) {
      return matches.back();
    } else {
      return std::nullopt;
    }
  }
};

/**
 * get_pattern_matcher builds a pattern matcher for the keywords.
 *
 * @return a const reference to the keyword pattern matcher.
 */
auto get_pattern_matcher() -> const kw_pattern & {
  static kw_pattern patterns;
  static std::once_flag pattern_builder;

  std::call_once(pattern_builder, [&]() {
    for (const auto &[pattern, kw_type] : kw_map) {
      patterns.add_alternative(pattern, kw_type);
    }
  });

  return patterns;
}

/**
 * keyword_decl contains
 */
export struct keyword_decl {
  keyword_type keyword;
};

/**
 * parse_keyword attempts to parse a keyword out of data.
 *
 * @param data the data stream to parse
 * @return a view of the unconsumed data and a keyword declaration on success, or
 * nothing on failure.
 */
export auto parse_keyword(position &p)
    -> std::optional<keyword_decl> {
  if (p.current_data.empty()) {
    return std::nullopt;
  }

  const auto &kws = get_pattern_matcher();
  const auto result = kws.match(p.current_data);

  if (!result) {
    return std::nullopt;
  }

  const auto &[consumed_chars, kw] = *result;
  p.current_data.remove_prefix(consumed_chars);
  p.column += consumed_chars;
  p.offset += consumed_chars;
  return keyword_decl{kw};
}

} // namespace cst