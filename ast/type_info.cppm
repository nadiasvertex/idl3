module;
#include <memory>
#include <variant>
export module ast.type_info;

import ast.package_decl;
import ast.data_type;

export namespace ast {

struct type_reference {
  data_type kind;

  std::shared_ptr<package_decl> pkg;
};
} // namespace ast