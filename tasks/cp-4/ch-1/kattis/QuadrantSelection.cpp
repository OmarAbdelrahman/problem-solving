#include <bits/stdc++.h>

using namespace std;

class QuadrantSelection {
public:
  void solve() {
    int x, y;
    in >> x >> y;
    if (x > 0 && y > 0)
      out << 1 << '\n';
    else if (x < 0 && y > 0)
      out << 2 << '\n';
    else if (x < 0 && y < 0)
      out << 3 << '\n';
    else
      out << 4 << '\n';
  }

  QuadrantSelection(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};