#include <bits/stdc++.h>
#include "../../../library/vector_utils.hpp"
using namespace std;

class CCanISquare {
public:
  inline bool is_perfect_square(int64_t x) {
    int64_t sr = int64_t(round(sqrt(x)));
    return (sr * sr == x);
  }

  void solveOne() {
    int n;
    in >> n;
    vector<int64_t> a(n);
    in >> a;
    int64_t s = accumulate(begin(a), end(a), INT64_C(0));
    if (is_perfect_square(s)) out << "YES\n"; else out << "NO\n";
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  CCanISquare(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};