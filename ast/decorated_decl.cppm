module;
#include <memory>
#include <string>
export module ast:decorated_decl;

import :decorator_decl;

export namespace ast {
/**
 * decorated_decl contains all the bits needed to allow a declaration to be
 * decorated.
 */
struct decorated_decl {
  std::vector<std::shared_ptr<decorated_decl>> decorators;
};
}