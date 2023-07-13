module;
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
    std::u8string filename;

    /**
     * line is the line number in the file where the position is located,
     * starting with 1.
     */
    std::uint32_t line=1;

    /**
     * column is the column number where the position is located, starting with 1.
     */
    std::uint32_t column=1;

    /**
     * data is the span of original data where the position occurs.
     */
    std::u8string_view data;
  };
}