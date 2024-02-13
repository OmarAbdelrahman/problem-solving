#include <bits/stdc++.h>

using namespace std;

class Jollo {
public:
  void solve() {
    while (true) {
      vector<int> f(F), m(M);
      in >> f[0] >> f[1] >> f[2] >> m[0] >> m[1];
      if (!f[0] && !f[1] && !f[2] && !m[0] && !m[1]) {
        break;
      }
      set<int> used({f[0], f[1], f[2], m[0], m[1]});
      sort(begin(f), end(f));
      sort(begin(m), end(m));
      int result = N + 1;
      if (m[0] > f[2]) {
        for (int which = 1; which <= N && which < result; which++) {
          if (!used.count(which))
            result = which;
        }
      }
      if (m[1] > f[2]) {
        for (int which = f[2] + 1; which <= N && which < result; which++) {
          if (!used.count(which))
            result = which;
        }
      }
      if (m[0] > f[1]) {
        for (int which = f[1] + 1; which <= N && which < result; which++) {
          if (!used.count(which))
            result = which;
        }
      }
      if (result == N + 1) result = -1;
      out << result << '\n';
    }
  }

  Jollo(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int N = 52;
  const int F = 3;
  const int M = 2;
};