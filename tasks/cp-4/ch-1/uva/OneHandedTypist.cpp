#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

class OneHandedTypist {
public:
  void solveOne(const std::string& line) {
    for (const char ch : line) {
      if (is_space(ch)) out << ch;
      else out << qwerty_to_dvorak[ch];
    }
    out << '\n';
  }

  void solve() {
    for (std::string line; std::getline(in, line); solveOne(line));
  }

  OneHandedTypist(std::istream& in, std::ostream& out)
    : in(in), out(out) 
  {
    for (std::size_t i = 0; i < ROWS; i++) {
      for (std::size_t j = 0; j < qwerty[i].size(); j++) {
        qwerty_to_dvorak[qwerty[i][j]] = dvorak[i][j];
      }
      for (std::size_t j = 0; j < QWERTY[i].size(); j++) {
        qwerty_to_dvorak[QWERTY[i][j]] = DVORAK[i][j];
      }
    }
  }

private:
  static inline bool is_space(const char ch) {
    return std::isspace(static_cast<unsigned char>(ch));
  }

private:
  std::istream& in;
  std::ostream& out;

  std::unordered_map<char, char> qwerty_to_dvorak;

  const std::vector<std::string> qwerty = {
    "`1234567890-=",
    " qwertyuiop[]\\",
    " asdfghjkl;'",
    " zxcvbnm,./"
  };

  const std::vector<std::string> QWERTY = {
    "~!@#$%^&*()_+",
    " QWERTYUIOP{}|",
    " ASDFGHJKL:\"",
    " ZXCVBNM<>?"
  };

  const std::vector<std::string> dvorak = {
    "`123qjlmfp/[]",
    " 456.orsuyb;=\\",
    " 789aehtdck-",
    " 0zx,inwvg'"
  };

  const std::vector<std::string> DVORAK = {
    "~!@#QJLMFP?{}",
    " $%^>ORSUYB:+|",
    " &*(AEHTDCK_",
    " )ZX<INWVG\""
  };

  const std::size_t ROWS = 4;
};
