#include <bits/stdc++.h>
#include "../../library/vector_utils.hpp"

using namespace std;

class BRaspberries {
public:
  void solveOne() {
    int n, k;
    in >> n >> k;
    vector<int> a(n);
    in >> a;
    int result = numeric_limits<int>::max();
    for (const int& ai: a) {
      result = min(result, (k - (ai % k)) % k);
    }
    if (k == 4 && n > 1) {
      int evens = 0;
      for (const int& ai : a) {
        evens += ai % 2 == 0;
      }
      result = min(result, max(0, 2 - evens));
    }
    out << result << '\n';
}

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BRaspberries(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};