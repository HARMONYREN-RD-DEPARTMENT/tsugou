#ifndef HARMONYREN_UTILS_LOG_HPP
#define HARMONYREN_UTILS_LOG_HPP

#include <harmonyren/utils/types.hpp>

namespace harmonyren {
namespace log {

constexpr const char *COLOR_RESET = "\033[0m";
constexpr const char *COLOR_LIGHT_GRAY = "\033[37m";
constexpr const char *COLOR_CYAN = "\033[36m";
constexpr const char *COLOR_YELLOW = "\033[33m";
constexpr const char *COLOR_RED = "\033[31m";

void info(const bool &condition, const String &msg);
void note(const bool &condition, const String &msg);
void warn(const bool &condition, const String &msg);
void fatal_error(const bool &condition, const String &msg, u32 err_code = 1);

} // namespace log

} // namespace harmonyren

#endif