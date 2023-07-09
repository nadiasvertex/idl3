module;
#include <memory>
export module ast:data_type;

export namespace ast {
enum class data_type {
  unknown,
  boolean,
  int8,
  int16,
  int32,
  int64,
  uint8,
  uint16,
  uint32,
  uint64,
  float32,
  float64,
  string,
  bytes,
  pipe,
  protocol_def,
  abstract_protocol_def,
  map_def,
  list_def,
  remote_list_def,
  remote_list_view_def,
  optional_def,
  message_def,
  enum_def,
  channel_def,
  const_ref,
  manager_ref,
  type_def,
  method_def,
  property_def,
  parameterized_def,
  template_def,
  package_def,
  splice_def,
  atom_def
};
} // namespace ast