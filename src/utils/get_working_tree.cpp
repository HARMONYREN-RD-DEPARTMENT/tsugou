#include <tsugou/utils.hpp>

#include <algorithm>

namespace tsugou {

Vector<String> get_working_tree(const String &path) {
  Vector<String> result;
  Vector<String> excludes = {".git", ".tsu"};

  Vector<std::filesystem::path> paths;
  for (const auto &entry :
       std::filesystem::recursive_directory_iterator(path)) {
    bool skip = false;
    for (const auto &part : entry.path()) {
      if (if_element_in_vector(part.string(), excludes)) {
        skip = true;
        break;
      }
    }
    if (skip)
      continue;

    paths.push_back(entry.path());
  }

  std::sort(paths.begin(), paths.end());

  for (const auto &entry : paths) {
    if (std::filesystem::is_regular_file(entry)) {
      result.push_back(entry.string());
    } else if (std::filesystem::is_directory(entry)) {
      if (std::filesystem::is_empty(entry)) {
        result.push_back(entry.string());
      }
    }
  }

  return result;
}

} // namespace tsugou
