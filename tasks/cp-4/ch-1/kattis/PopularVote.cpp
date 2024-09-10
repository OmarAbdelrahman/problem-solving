#include <bits/stdc++.h>

#include "../../../../library/io.hpp"

using namespace std;
using namespace io;

class PopularVote {
public:
  void solve() {
    int nt;
    in >> nt;
    while (nt--) {
      int n;
      in >> n;
      vector<int> v(n);
      in >> v;
      int s = 0, j = 0, b = -1;
      for (int i = 0; i < n; i++) {
        s += v[i];
        if (v[i] > b) {
          b = v[i];
          j = i + 1;
        }
      }
      if (count(begin(v), end(v), b) > 1) {
        out << "no winner" << '\n';
      } else {
        out << value_conditional(b * 2 > s, {"minority", "majority"}) << " winner " << j << '\n';
      }
    }
  }

  void print_yes_or_no(std::ostream& o, const bool& condition, const bool new_line = true) {
    o << (condition ? "YES" : "NO") << (new_line ? '\n' : char());
  }
  std::string yes_or_no(const bool condition) {
    return condition ? "YES" : "NO";
  }
  template<typename T = std::string>
  T value_conditional(const bool condition, const std::array<T, 2>& options) {
    return options[condition];
  }
  template<typename T = std::string>
  void print_conditional(std::ostream& o, const bool condition, const std::array<T, 2>& options, const bool new_line = true) {
    o << options[condition] << (new_line ? '\n' : char());
  }
  template<typename T>
  void print_case(std::ostream& o, const int case_i, const T& result, const bool new_line = true) {
    o << "Case " << case_i << ": " << result << (new_line ? '\n' : char());
  }

  PopularVote(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};