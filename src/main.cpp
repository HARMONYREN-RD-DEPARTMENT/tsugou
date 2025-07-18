#include <iostream>

#include <tsugou/utils.hpp>

using namespace tsugou;

int main() {

  std::cout << get_working_tree_hash_state() << std::endl;

  return 0;
}
