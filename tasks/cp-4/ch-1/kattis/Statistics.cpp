#include <bits/stdc++.h>

using namespace std;

class Statistics {
public:
  void solve() {
    for (int _ = 0, n; in >> n; _++) {
      int b = numeric_limits<int>::min();
      int s = numeric_limits<int>::max();
      while (n--) {
        int a;
        in >> a;
        b = max(b, a);
        s = min(s, a);
      }
      out << "Case " << _ + 1 << ": " << s << ' ' << b << ' ' << b - s << '\n';
    }
  }

  Statistics(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};