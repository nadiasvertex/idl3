module;
#include<string>
export module ast:primitive_decl;

import :data_type;

export namespace ast {
  struct primitive_decl {
    std::string name;

    data_type kind;
  };
}