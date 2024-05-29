#include <bits/stdc++.h>
#include "../../library/vector_utils.hpp"
#include "../../library/pair_io.hpp"

using namespace std;

class AGeorgeAndAccommodation {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<pair<int, int>> a(n);
    in >> a;
    out << count_if(begin(a), end(a), [](const auto& p) { return p.second - p.first >= 2; }) << '\n';
  }

  void solve() {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AGeorgeAndAccommodation(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};