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

std::vector<std::tuple<std::u8string_view, keyword_type>> kw_map = {
    {u8"abstract", keyword_type::abstract_kw},
    {u8"const", keyword_type::const_kw},
    {u8"enum", keyword_type::enum_kw},
    {u8"import", keyword_type::import_kw},
    {u8"message", keyword_type::message_kw},
    {u8"operation", keyword_type::operation_kw},
    {u8"package", keyword_type::package_kw},
    {u8"protocol", keyword_type::protocol_kw},
    {u8"splice", keyword_type::splice_kw},
    {u8"template", keyword_type::template_kw},
    {u8"type", keyword_type::type_kw},
    {u8"using", keyword_type::using_kw},
    {u8"with", keyword_type::with_kw}};

struct kw_pattern_state {
  std::optional<std::u8string::value_type> value;
  std::optional<keyword_type> keyword;
  std::vector<kw_pattern_state> next_states;
};

/**
 * kw_pattern holds the start states for all patterns and functions to mutate
 * and query the pattern states.
 */
struct kw_pattern {
  using size_type = std::u8string_view::size_type;
  std::vector<kw_pattern_state> patterns;

  /**
   * add_alternative adds a pattern into the pattern state tree, and assigns
   * it to a keyword enum.
   *
   * @param pattern the pattern to add
   * @param kw the keyword end state
   */
  void add_alternative(std::u8string_view pattern, keyword_type kw) {
    auto &ps = patterns;
    for (const auto &c : pattern) {
      auto pos = std::ranges::find_if(ps, [&c](kw_pattern_state &state) {
        return state.value.has_value() && state.value == c;
      });

      // If 'c' doesn't exist in the state vector, add it and move down that
      // subtree.
      if (pos == ps.end()) {
        ps.emplace_back(c);
        ps = ps.back().next_states;
      } else {
        ps = pos->next_states;
      }
    }

    ps.emplace_back(std::nullopt, kw);
  }

  /**
   * match tries to match 'data' in the pattern tree and if successful indicates
   * how much data was consumed and which keyword was found. On a failed match
   * it returns nothing.
   *
   * @param data the data to search.
   * @return a count of consumed data and the keyword found on success, or
   * nothing.
   */
  [[nodiscard]] auto match(std::u8string_view data) const
      -> std::optional<std::tuple<size_type, keyword_type>> {
    auto ps = std::cref(patterns);
    std::vector<std::tuple<size_type, keyword_type>> matches;
    for (std::string_view::size_type index = 0; index < data.size(); ++index) {
      auto pos = std::ranges::find_if(
          ps.get(), [c = data[index]](const kw_pattern_state &state) {
            return state.value.has_value() && state.value == c;
          });

      if (pos == ps.get().end()) {
        break;
      } else {
        ps = pos->next_states;
        if (pos->keyword) {
          matches.emplace_back(index, *pos->keyword);
        }
      }
    }

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
 * @return a view of the unconsumed data and a keyword declaration on sucess, or nothing on failure.
 */
export auto parse_keyword(std::u8string_view data)
    -> std::optional<std::tuple<std::u8string_view, keyword_decl>> {
  const auto &kws = get_pattern_matcher();
  const auto result = kws.match(data);

  if (!result) {
    return std::nullopt;
  }

  const auto &[consumed_chars, kw] = *result;
  data.remove_prefix(consumed_chars);
  return std::make_tuple(data, keyword_decl{kw});
}

} // namespace cst