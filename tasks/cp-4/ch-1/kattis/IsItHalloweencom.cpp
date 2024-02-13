#include <bits/stdc++.h>
#include "../../../../library/io_utils.hpp"
using namespace std;

class IsItHalloweencom {
public:
  void solve() {
    string s;
    int n;
    in >> s >> n;
    print_conditional(out, (s == "OCT" && n == 31) || (s == "DEC" && n == 25), {"nope", "yup"});
  }

  IsItHalloweencom(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};