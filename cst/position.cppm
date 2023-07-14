module;
#include <format>
#include <string>
export module cst:position;

export namespace cst {
/**
 * position tracks the location and data span of a concrete syntax element.
 */
struct position {
  /**
   * filename is the name of the file where the position is located.
   */
  std::string filename;

  /**
   * line is the line number in the file where the position is located,
   * starting with 1.
   */
  std::uint32_t line = 1;

  /**
   * column is the column number where the position is located, starting with 1.
   */
  std::uint32_t column = 1;

  /**
   * offset is the index into original data where the position occurs.
   */
  std::string_view::size_type offset{};

  /**
   * current_data is view of the data that was unconsumed when this position
   * was captured.
   */
  std::string_view current_data;

  /**
   * data is a view of the entire data set provided to the parser.
   */
  std::string_view data;

  void consume() {
    offset++;
    column++;
  }

  auto error_message(std::string_view message) {
    return std::format("{}:{}:{}: error: {}\n", filename, line, column,
                       message) + source_stencil();
  }

private:
  /**
   * get_line provides the entire line of source surrounding this position
   * object.
   *
   * @return the line of source code represented by this position.
   */
  [[nodiscard]] auto get_line() const -> std::string_view {
    auto start_pos = data.begin() + offset;
    auto end_pos = data.begin() + offset;

    while (*start_pos != '\n' && start_pos != data.begin()) {
      start_pos--;
    }
    while (*end_pos != '\n' && end_pos != data.end()) {
      end_pos++;
    }

    return {start_pos, end_pos};
  }

  /**
   * source_stencil generates a line of source code with a marker at the location
   * pointed to by this position object.
   *
   * @param columns_allowed the column budget allowed to display the stencil
   * @return a source stencil with the line of source code surrounding this position, and a marker at the position.
   */
  [[nodiscard]] auto source_stencil(std::string::size_type columns_allowed = 78)
      -> std::string {
    auto prefix = std::format("{}", line);
    auto marker_column = column;
    auto source_line = get_line();
    if (source_line.size() + prefix.size() >= columns_allowed) {
      std::tie(source_line, marker_column) =
          trim_line(columns_allowed - prefix.size(), source_line);
    }
    auto padding1 = std::string(prefix.size(), ' ');
    auto padding2 = std::string(marker_column - 1, ' ');
    return std::format("{} | {}\n{} | {}^\n", prefix, source_line, padding1,
                       padding2);
  }

  /**
   * trim_line trims the line so that it will fit in the requested
   * column_budget.
   *
   * @param columns_allowed the column budget.
   * @param source_line the original line of source.
   * @return the trimmed line.
   */
  [[nodiscard]] std::tuple<std::string_view, std::string_view::size_type>
  trim_line(std::string_view::size_type columns_allowed,
            std::string_view source_line) const {

    /*
     * The place where the marker occurs can be at the end of the
     * line, the beginning, or somewhere in the middle. We have a
     * fixed budget of text that we can display, and we want the
     * maximum context around the column where the indicator should
     * appear. We compute the left and right borders by moving both
     * offsets to their extremes from the center until our budget is
     * expended.
     */

    auto budget = columns_allowed;
    auto left_index = column;
    auto right_index = column;
    while (budget > 1) {
      if (right_index < source_line.size()) {
        right_index++;
        budget--;
      }
      if (left_index > 1) {
        left_index--;
        budget--;
      }
    }
    return {source_line.substr(left_index, right_index - left_index),
            column - left_index};
  }
};
} // namespace cst