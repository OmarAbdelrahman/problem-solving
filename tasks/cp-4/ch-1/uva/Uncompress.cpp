#include <iostream>
#include <string>
#include <deque>

#include "../../../../library/char_utils.hpp"

class Uncompress {
public:
  void solveOne(const std::string& line) {
    std::string word;
    for (std::size_t i = 0; i < line.size(); i++) {
      const char ch = line[i];
      if (is_digit(ch)) {
        int at = 0;
        while (is_digit(line[i])) {
          at = at * 10 + (line[i] - '0');
          i += 1;
        }
        i -= 1;
        out << words[at - 1];
        words.emplace_front(words[at - 1]);
        words.erase(words.begin() + at);
      } else if (is_alpha(ch)) {
        word += ch;
      } else {
        if (word.empty()) out << ch;
        else {
          words.emplace_front(word);
          out << word << ch;
          word.clear();
        }
      }
    }
    if (!word.empty()) {
      words.emplace_front(word);
      out << word;
    }
    out << '\n';
  }

  void solve() {
    words.clear();
    for (std::string line; std::getline(in, line) && line != "0"; ) {
      solveOne(line);
    }
  }

  Uncompress(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  std::deque<std::string> words;
};