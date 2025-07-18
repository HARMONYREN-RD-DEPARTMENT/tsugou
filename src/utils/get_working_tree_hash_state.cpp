#include <tsugou/utils.hpp>

namespace tsugou {

String get_working_tree_hash_state() {
  Map<String, String> working_tree = get_working_tree_hashed_files();
  String output = "";
  for (auto &entry : working_tree) {
    output += entry.first + " " + entry.second + "\n";
  }

  return sha3_256(output);
}

} // namespace tsugou