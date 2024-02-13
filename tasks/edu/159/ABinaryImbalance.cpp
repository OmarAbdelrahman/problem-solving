#include <bits/stdc++.h>

using namespace std;

class ABinaryImbalance {
public:
  void solveOne() {
    int n;
    in >> n;
    string s;
    in >> s;
    int zeros = count(begin(s), end(s), '0');
    if (!zeros) {
      out << "NO" << '\n';
    } else {
      out << "YES" << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ABinaryImbalance(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};