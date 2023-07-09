module;
#include <variant>
export module ast:decl;

import :protocol_decl;
import :primitive_decl;


export namespace ast {
  using decl = std::variant<protocol_decl, primitive_decl>;
}
