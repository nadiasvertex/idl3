module;
#include <string>
#include <vector>
export module ast:decorator_decl;

import :field_decl;

export namespace ast {

struct decorator_decl {
  std::string name;
  std::vector<field_decl> inputs;
};
}