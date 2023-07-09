module;
#include <memory>
#include <string>
export module ast:type_descriptor;

import :data_type;
import :decl;

export namespace ast {
/**
 * type_descriptor contains information describing the type of any typed thing
 * in IDL.
 */
struct type_descriptor {
  data_type kind;

  /**
   * declaration contains a shared pointer to the declaration of the type that
   * this object points to.
   */
  std::shared_ptr<decl> declaration;

  /**
   * path is the list of names that identify this type name from the root to
   * the most closely nested package.
   */
  std::vector<std::u8string> path;
};
}