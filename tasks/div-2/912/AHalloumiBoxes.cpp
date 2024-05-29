#include <bits/stdc++.h>
#include "../../../library/vector_utils.hpp"

using namespace std;

class AHalloumiBoxes {
public:
  void solveOne() {
    int n, k;
    in >> n >> k;
    vector<int> a(n);
    in >> a;
    if (k == 1 && !is_sorted(begin(a), end(a))) {
      out << "NO\n";
    } else {
      out << "YES\n";
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AHalloumiBoxes(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};