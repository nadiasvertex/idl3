module;
#include <memory>
#include <string>
#include <vector>
export module ast:protocol_decl;

export namespace ast {
struct protocol_decl {
  std::u8string name;

  bool abstract;
  // std::vector<method_decl> methods;
};
} // namespace ast