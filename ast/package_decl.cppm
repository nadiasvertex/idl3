module;
#include <string>
#include <variant>
#include <vector>
#include <unordered_map>
export module ast.package_decl;

import ast.using_decl;

export namespace ast{
struct package_decl {
  std::u8string name;

  std::vector<using_decl> aliases;
  std::unordered_map<std::u8string, std::u8string> alias_map;
};
}