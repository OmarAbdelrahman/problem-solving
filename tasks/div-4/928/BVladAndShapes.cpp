#include <bits/stdc++.h>

#include "../../../library/vector_utils.hpp"
#include "../../../library/debug.hpp"
using namespace std;

class BVladAndShapes {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<string> a(n);
    in >> a;
    vector<int> cnt;
    for (const auto& str : a) {
      cnt.push_back((int) count(begin(str), end(str), '1'));
      if (cnt.back() == 0) cnt.pop_back();
    }
    debug(cnt);
    if (all_of(begin(cnt), end(cnt), [&](int v) { return v == cnt.front(); })) {
      out << "SQUARE" << '\n';
    } else {
      out << "TRIANGLE" << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  BVladAndShapes(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};