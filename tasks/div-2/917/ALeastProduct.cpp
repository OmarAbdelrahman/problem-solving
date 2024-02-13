#include <bits/stdc++.h>
#include "../../../library/vector_io.hpp"
using namespace std;

class ALeastProduct {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int64_t> a(n);
    in >> a;
    int s = 1;
    if (ranges::find(a, 0) != end(a)) {
      out << 0 << '\n';
      return;
    }
    int negs = ranges::count_if(a, [](const int64_t& e) { return e < 0; });
    if (negs % 2 == 0) {
      out << 1 << '\n';
      out << 1 << ' ' << 0 << '\n';
    } else {
      out << 0 << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ALeastProduct(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};