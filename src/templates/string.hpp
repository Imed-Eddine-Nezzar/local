#ifndef __LOCAL_TEMPLATES_STRING_HPP__
#define __LOCAL_TEMPLATES_STRING_HPP__

#include <string>
#include <vector>
#include <sstream>

namespace local {

  class any_of {
    any_of() = delete;

    any_of(const char* c_str) :
      m_seps(c_str)
    {}

    any_of(std::string str) :
      m_seps(str)
    {}

    bool operator()(char c) const
    {
      for (const auto& ch : m_seps) {
        if (c == ch)
          return true;
      }

      return false;
    }


  private:
    std::string m_seps;
  };

  template <
    typename Container = std::vector<std::string>
  >
  auto split(const std::string& str, Container cnt = {}, any_of sep = any_of(" \n\t\v")) -> decltype(cnt) {
    std::istringstream stream(str);
    std::string token;
    while (std::getline(stream, token, sep)) {

    }
  }

} // namespace local

#endif // __LOCAL_TEMPLATES_STRING_HPP__
