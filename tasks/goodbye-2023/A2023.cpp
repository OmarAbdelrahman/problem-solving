#include <bits/stdc++.h>
#include "../../library/vector_io.hpp"
#include "../../library/debug.hpp"

using namespace std;

class A2023 {
public:
  void solveOne() {
    int n, k;
    in >> n >> k;
    vector<int> b(n);
    in >> b;
    vector<int> ds = {1, 7, 17, 119, 289, 2023};
    int p = 1;
    for (const int& bi : b) {
      if (find(begin(ds), end(ds), bi) == end(ds)) {
        out << "NO" << '\n';
        return;
      }
      p *= bi;
    }
    if (2023 % p == 0) {
      out << "YES\n";
      out << 2023 / p;
      for (int i = 0; i < k - 1; i++) {
        out << " 1";
      }
      out << '\n';
    } else {
      out << "NO\n";
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  A2023(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};