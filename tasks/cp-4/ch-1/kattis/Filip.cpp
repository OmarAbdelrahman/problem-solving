#include <bits/stdc++.h>
#include "../../../../library/io_utils.hpp"
using namespace std;

class Filip {
public:
  void solve() {
    string a, b;
    in >> a >> b;
    reverse(begin(a), end(a));
    reverse(begin(b), end(b));
    print_conditional(out, a > b, {b, a});
  }

  Filip(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};