#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>

#include "../../../../library/vector_utils.hpp"

/*
 * I was getting WA when using
 *  `std::nth_element(names.begin(), names.begin() + (m - 1), names.end())`
 *  `std::nth_element(names.begin(), names.begin() + m, names.end())`
 * Got it accepted when changed to std::sort ..., not sure why still, but the idea is the same
 */
class PartyGames {
public:
  void solve() {
    for (int n; in >> n && n; ) {
      std::vector<std::string> names(n);
      in >> names;
      const int m = n / 2;
      std::sort(names.begin(), names.end());
      const std::string& L = names[m - 1];
      const std::string& R = names[m];
      std::string result;
      for (std::size_t i = 0; i < L.size(); i++) {
        bool found = false;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
          const std::string candidate = result + ch;
          if (L <= candidate && candidate < R) {
            result += ch;
            found = true;
            break;
          }
        }
        if (found) break; else result += L[i];
      }
      out << result << '\n';
    }
  }

  PartyGames(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

};