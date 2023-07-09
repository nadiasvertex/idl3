module;
#include <string>
#include <variant>
#include <vector>
#include <unordered_map>
export module ast:package_decl;

import :using_decl;
import :protocol_decl;

export namespace ast{

using package_member = std::variant<using_decl, protocol_decl>;

struct package_decl {
  std::u8string name;

  std::vector<using_decl> aliases;
  std::unordered_map<std::u8string, std::u8string> alias_map;
};
}