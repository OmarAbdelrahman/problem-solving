#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "../../../../library/vector_utils.hpp"

class LetsPlayMagic {
public:
  void solve() {
    for (int n; in >> n && n != 0; ) {
      std::vector<std::string> cards(n, "");
      int at = 0;
      for (int i = 0; i < n; i++) {
        std::string card, word;
        in >> card >> word;
        for (std::size_t k = 0; k < word.length(); ) {
          if (cards[at].empty()) {
            at = (at + 1) % n;
            k += 1;
          } else {
            at = (at + 1) % n;
          }
        }
        if (at - 1 < 0) {
          cards.back() = card;
        } else {
          cards[at - 1] = card;
        }
      }
      out << cards << '\n';
    }
  }

  LetsPlayMagic(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};