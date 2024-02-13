#include <bits/stdc++.h>
using namespace std;

class BossBattle {
public:
  void solve() {
    int n;
    in >> n;
    out << max(1, n - 2) << '\n';
  }

  BossBattle(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};