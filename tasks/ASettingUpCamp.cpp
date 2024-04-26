#include <bits/stdc++.h>

using namespace std;

class ASettingUpCamp {
public:
  void solveOne() {
    int64_t a, b, c;
    in >> a >> b >> c;
    if (b % 3 == 0) {
      int64_t u = min((c / 3) + (c % 3 != 0), (c / 2) + (c % 2 != 0));
      out << a + (b / 3) + u << '\n';
    } else if (b % 3 == 2) {
      if (c < 1) out << -1 << '\n'; else {
        int64_t r = a + ((b + 1) / 3);
        int64_t u = min(((c - 1) / 3) + ((c - 1) % 3 != 0), ((c - 1) / 2) + ((c - 1) % 2 != 0));
        out << r + u << '\n';
      }
    } else {
      if (c < 2) out << -1 << '\n'; else {
        int64_t r = a + ((b + 2) / 3);
        int64_t u = min(((c - 2) / 3) + ((c - 2) % 3 != 0), ((c - 2) / 2) + ((c - 2) % 2 != 0));
        out << r + u << '\n';
      }
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  ASettingUpCamp(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};