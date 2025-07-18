#ifndef TSUGOU_UTILS_HPP
#define TSUGOU_UTILS_HPP

#include <harmonyren/utils/types.hpp>

#include <filesystem>

namespace tsugou {
using namespace harmonyren;

namespace fs = std::filesystem;

template <typename T> bool if_element_in_vector(T element, Vector<T> vector) {
  for (T item : vector) {
    if (item == element) {
      return true;
    }
  }
  return false;
}

String bytes_to_hex_string(const Vector<u8> &bytes);
Vector<String> get_working_tree(const String &path);
Map<String, String> get_working_tree_hashed_files();
String get_working_tree_hash_state();

String sha3_256(const String &input);

} // namespace tsugou

#endif
