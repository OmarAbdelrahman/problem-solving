#include <bits/stdc++.h>
using namespace std;

class AmalgamatedArtichokes {
public:
  void solve() {
    int p, a, b, c, d, n;
    in >> p >> a >> b >> c >> d >> n;
    double so_far = -INF, decline = -INF;
    for (int k = 1; k <= n; k++) {
      double pk = p * (sin(a * k + b) + cos(c * k + d) + 2);
      so_far = max(so_far, pk);
      decline = max(decline, so_far - pk);
    }
    out << fixed << setprecision(6) << decline << '\n';
  }

  AmalgamatedArtichokes(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const double INF = numeric_limits<double>::max() / 2;
};