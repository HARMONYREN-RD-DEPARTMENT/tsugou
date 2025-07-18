#ifndef TSUGOU_PARTICIPANT_HPP
#define TSUGOU_PARTICIPANT_HPP

#include <harmonyren/utils/types.hpp>

namespace tsugou {

using namespace harmonyren;

class Participant {
  private:
    String username;
    Map<String, String> contacts;
  
  public:
    Participant();

    static Participant from_yml();
    static Participant from_string(const String& str);

    String get_username() const;
    Map<String, String> get_contacts() const;
};

}

#endif