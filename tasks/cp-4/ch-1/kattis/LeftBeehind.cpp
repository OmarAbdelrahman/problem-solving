#include <bits/stdc++.h>

using namespace std;

class LeftBeehind {
public:
  void solve() {
    for (int x, y; in >> x >> y && (x != 0 || y != 0); ) {
      if (x + y == 13) {
        out << "Never speak again.";
      } else if (x > y) {
        out << "To the convention.";
      } else if (x < y) {
        out << "Left beehind.";
      } else {
        out << "Undecided.";
      }
      out << '\n';
    }
  }

  LeftBeehind(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};