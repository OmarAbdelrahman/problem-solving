#include <bits/stdc++.h>

#include "../../../../library/io.hpp"

using namespace std;
using namespace io;

class LineThemUp {
public:
  void solve() {
    int nt;
    in >> nt;
    vector<string> s(nt);
    in >> s;
    bool inc = true, dec = true;
    for (int i = 1; i < nt; i++) {
      inc &= s[i - 1] < s[i];
      dec &= s[i - 1] > s[i];
    }
    if (inc ^ dec) {
      print_conditional(out, inc, {"DECREASING", "INCREASING"});
    } else {
      out << "NEITHER" << '\n';
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

  LineThemUp(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};