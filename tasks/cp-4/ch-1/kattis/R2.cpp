#include <bits/stdc++.h>

using namespace std;

class R2 {
public:
  void solve() {
    int r1, s;
    in >> r1 >> s;
    out << 2 * s - r1 << '\n';
  }

  R2(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};