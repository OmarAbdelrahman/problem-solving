#include <bits/stdc++.h>

#include "../../../library/vector_utils.hpp"
using namespace std;

class DVladAndDivision {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    multiset<int> s;
    int r = 0;
    for (const int& ai : a) {
      const int c = ((1 << 31) - 1) ^ ai;
      if (!s.contains(ai)) {
        r += 1;
        s.insert(c);
      } else {
        s.extract(ai);
      }
    }
    out << r << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  DVladAndDivision(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};