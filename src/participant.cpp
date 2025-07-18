#include <tsugou/participant.hpp>

namespace tsugou {

Participant::Participant() {
  this->username = "";
  this->contacts = Map<String, String>();
}

std::string Participant::get_username() const { return this->username; }
Map<String, String> Participant::get_contacts() const { return this->contacts; }

Participant Participant::from_string(const String &str) {
  Participant p;
  return p;
}

} // namespace tsugou