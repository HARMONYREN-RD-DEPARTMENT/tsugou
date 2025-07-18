#include <tsugou/utils.hpp>

#include <fstream>

namespace tsugou {

Map<String, String> get_working_tree_hashed_files() {
  Vector<String> working_tree = get_working_tree(".");

  Map<String, String> result;

  std::ifstream file;
  for (const auto &entry : working_tree) {
    file.open(entry);
    if (file.is_open()) {
      if (file.peek() == std::ifstream::traits_type::eof()) {
        result[entry] = "";
      } else {
        result[entry] = std::string((std::istreambuf_iterator<char>(file)),
                                    std::istreambuf_iterator<char>());
      }

      file.close();
    }
  }

  for (auto &entry : result) {
    entry.second = sha3_256(entry.first + " " + sha3_256(entry.second));
  }

  return result;
}

} // namespace tsugou