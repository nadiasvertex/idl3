module;
#include <string>
export module ast:field_decl;

import :type_descriptor;

export namespace ast {

/**
 * field_decl represents a field in a message or operation.
 */
struct field_decl {
  /**
   * name is the name of the field.
   */
  std::u8string name;

  /**
   * type contains information about the type of the field.
   */
  type_descriptor type;

  std::u8string tag;
};
}
