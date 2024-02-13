#include <bits/stdc++.h>
#include "../../../../library/io_utils.hpp"
using namespace std;

class PackingForHoliday {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0, a, b, c; _ < nt; _++) {
      out << "Case " << _ + 1 << ": ";
      in >> a >> b >> c;
      print_conditional(out, a <= 20 && b <= 20 && c <= 20, {"bad", "good"});
    }
  }

  PackingForHoliday(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};