module;
#include <string>
export module ast:using_decl;

export namespace ast {
struct using_decl {
  std::u8string old_name;
  std::u8string new_name;
};
}