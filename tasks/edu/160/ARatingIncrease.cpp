#include <bits/stdc++.h>

using namespace std;

class ARatingIncrease {
public:
  void solveOne() {
    string s;
    in >> s;
    const int n = ssize(s);
    for (int i = 1; i <= n; i++) {
      string a = s.substr(0, i);
      string b = s.substr(i);
      if (a[0] == '0' || b[0] == '0') {
        continue;
      }
      stringstream ss(a + " " + b);
      int ai, bi;
      ss >> ai >> bi;
      if (ai < bi && to_string(ai) + to_string(bi) == s) {
        out << ai << ' ' << bi << '\n';
        return;
      }
    }
    out << -1 << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ARatingIncrease(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};