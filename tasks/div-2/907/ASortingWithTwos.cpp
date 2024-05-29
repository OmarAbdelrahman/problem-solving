#include <bits/stdc++.h>
#include "../../../library/vector_utils.hpp"

using namespace std;

class ASortingWithTwos {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    for (int p = 0; p < 10; p++) {
      int subset = 1 << p;
      if (subset < n && a[subset - 1] > a[subset]) {
        int diff = a[subset - 1] - a[subset];
        for (int i = 0; i < subset; i++) {
          a[i] -= diff;
        }
      }
    }
    if (is_sorted(begin(a), end(a))) out << "YES" << '\n'; else out << "NO" << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ASortingWithTwos(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};