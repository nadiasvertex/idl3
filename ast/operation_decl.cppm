module;
#include <string>
#include <vector>
export module ast:operation_decl;

import :field_decl;

export namespace ast {
/**
 * operation_decl captures information about operations. In previous versions
 * of IDL these were known as methods or RPCs.
 */
struct operation_decl {
  std::string name;

  std::vector<field_decl> inputs;
  std::vector<field_decl> outputs;

  bool throws = false;
  bool is_static = false;
};
}