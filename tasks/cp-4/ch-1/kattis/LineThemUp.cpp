#include <bits/stdc++.h>
#include "../../../../library/vector_io.hpp"
#include "../../../../library/io_utils.hpp"
using namespace std;

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

  LineThemUp(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};