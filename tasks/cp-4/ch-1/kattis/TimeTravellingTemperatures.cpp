#include <bits/stdc++.h>

using namespace std;

class TimeTravellingTemperatures {
public:
  void solve() {
    double x, y;
    in >> x >> y;
    if (x == 0 && y == 1)
      out << "ALL GOOD" << '\n';
    else if (y == 1)
      out << "IMPOSSIBLE" << '\n';
    else
      out << fixed << setprecision(6) << x / (1 - y) << '\n';
  }

  TimeTravellingTemperatures(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};