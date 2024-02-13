#include <bits/stdc++.h>

using namespace std;

class JudgingMoose {
public:
  void solve() {
    int n, m;
    in >> n >> m;
    if (n + m == 0) {
      out << "Not a moose" << '\n';
    } else if (n == m) {
      out << "Even " << n + m << '\n';
    } else {
      out << "Odd " << max(n, m) * 2 << '\n';
    }
  }

  JudgingMoose(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};