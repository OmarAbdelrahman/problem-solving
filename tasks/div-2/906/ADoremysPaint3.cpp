#include <bits/stdc++.h>
using namespace std;

#define _size(a) (int) (a).size()

class ADoremysPaint3 {
public:
  void solveOne(istream& in, ostream& out) {
    int n;
    in >> n;
    vector<int> a(n);
    for (int& ai : a) {
      in >> ai;
    }
    map<int, int> f;
    for (const int& ai : a) {
      f[ai]++;
    }
    if (_size(f) > 2) {
      out << "No\n";
    } else if (abs(f.begin()->second - f.rbegin()->second) > 1) {
      out << "No\n";
    } else {
      out << "Yes\n";
    }
  }

  void solve(istream& in, ostream& out) {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }
};