#include <bits/stdc++.h>
#include "../../library/vector_utils.hpp"

using namespace std;

class CInsertAndEqualize {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    unordered_map<int, bool> taken;
    for (const int& ai : a) {
      taken[ai] = true;
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  CInsertAndEqualize(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};