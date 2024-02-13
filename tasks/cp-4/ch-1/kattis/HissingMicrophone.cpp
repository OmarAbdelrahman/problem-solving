#include <bits/stdc++.h>
#include "../../../../library/io_utils.hpp"
using namespace std;

class HissingMicrophone {
public:
  void solve() {
    string s;
    in >> s;
    print_conditional(out, s.find("ss") != string::npos, {"no hiss", "hiss"});
  }

  HissingMicrophone(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};