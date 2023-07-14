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
  std::string name;

  std::vector<using_decl> aliases;
  std::unordered_map<std::string, std::string> alias_map;
};
}