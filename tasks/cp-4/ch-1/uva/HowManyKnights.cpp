#include <bits/stdc++.h>

using namespace std;

class HowManyKnights {
public:
  int solve(int n, int m) {
    if (n > m) swap(n,m);
    if (n == 1) return m;
    if (n == 2) return m / 4 * 4 + (m % 4 == 1 ? 2 : (m % 4 >= 2 ? 4 : 0));
    return (n * m + 1) / 2;
  }

  void solve() {
    for (int n, m; in >> n >> m; ) {
      if (n == 0 && m == 0) break;
      out << solve(n, m) << " knights may be placed on a " << n << " row " << m << " column board." << '\n';
    }
  }

  HowManyKnights(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};