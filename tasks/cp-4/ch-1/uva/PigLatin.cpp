#include <iostream>
#include <string>
#include <cctype>

#include "../../../../library/char_utils.hpp"

class PigLatin {
public:
  void solveOne(const std::string& line) {
    std::string word;
    for (const char ch : line) {
      if (!is_alpha(ch)) {
        if (word.empty()) out << ch;
        else {
          if (is_vowel(word.front())) out << word + "ay";
          else out << word.substr(1) + word.front() + "ay";
          out << ch;
          word.clear();
        }
      } else {
        word += ch;
      }
    }
    out << '\n';
  }

  void solve() {
    for (std::string line; std::getline(in, line); solveOne(line));
  }

  PigLatin(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};