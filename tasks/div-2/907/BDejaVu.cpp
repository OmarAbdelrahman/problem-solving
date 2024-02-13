#include <bits/stdc++.h>
#include "../../../library/vector_io.hpp"
using namespace std;

class BDejaVu {
public:
  void solveOne() {
    int n, q;
    in >> n >> q;
    vector<int> a(n), x(q);
    in >> a;
    in >> x;
    vector<vector<int>> locations(BITS + 1);
    for (int i = 0; i < n; i++) {
      locations[__countr_zero(a[i])].push_back(i);
    }
    for (const int& xi : x) {
      for (int bit = xi; bit <= BITS; bit++) {
        for (const int& index : locations[bit]) {
          a[index] += 1 << (xi - 1);
          locations[xi - 1].push_back(index);
        }
        locations[bit].clear();
      }
    }
    out << a << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  BDejaVu(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int BITS = 30;
};