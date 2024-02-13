#include <bits/stdc++.h>

using namespace std;

class Tarifa {
public:
  void solve() {
    int x;
    in >> x;
    int n;
    in >> n;
    int r = (n + 1) * x;
    while (n--) {
      int a;
      in >> a;
      r -= a;
    }
    out << r << '\n';
  }

  Tarifa(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};