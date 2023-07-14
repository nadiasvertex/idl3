module;
#include <string>
export module ast:using_decl;

export namespace ast {
struct using_decl {
  std::string old_name;
  std::string new_name;
};
}