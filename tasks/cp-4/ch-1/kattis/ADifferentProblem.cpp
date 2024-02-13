#include <bits/stdc++.h>

using namespace std;

class ADifferentProblem {
public:
  void solve() {
    for (int64_t a, b; in >> a >> b; out << abs(a - b) << '\n');
  }

  ADifferentProblem(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};