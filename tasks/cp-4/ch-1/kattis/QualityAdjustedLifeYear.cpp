#include <bits/stdc++.h>

using namespace std;

class QualityAdjustedLifeYear {
public:
  void solve() {
    int n;
    in >> n;
    double res = 0.0;
    while (n--) {
      double a, b;
      in >> a >> b;
      res += a * b;
    }
    out << fixed << setprecision(3) << res << '\n';
  }

  QualityAdjustedLifeYear(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};