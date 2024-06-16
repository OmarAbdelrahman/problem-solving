#include <bits/stdc++.h>
#include "../../../library/suffix_array.hpp"
#include "../../../library/sparse_table.hpp"
#include "../../../library/pair_utils.hpp"
#include "../../../library/vector_utils.hpp"
using namespace std;

class CSortingSubstrings {
public:
  void solveOne(istream& in, ostream& out) {
    in >> s;
    in >> n;
    subs = vector<pair<int, int>>(n);
    in >> subs;
    suffix_array_t sa(s);
    sparse_table<int> spt(sa._lcp(), [&](const int& a, const int& b) -> int { return min(a, b); });
    sort(begin(subs), end(subs), [&](const auto& p1, const auto& p2) -> bool {
      auto [x1, y1] = p1;
      auto [x2, y2] = p2;
      if (x1 == x2) {
        return y1 < y2;
      }
      int n1 = y1 - x1 + 1;
      int n2 = y2 - x2 + 1;
      int px1 = sa.suffix_pos(x1 - 1);
      int px2 = sa.suffix_pos(x2 - 1);
      int i = min(px1, px2);
      int j = max(px1, px2);
      int lcp_m = spt.get(i + (int) (i != j), j);
      if (lcp_m < n1 && lcp_m < n2) {
        return px1 < px2;
      }
      if (lcp_m >= n1 && lcp_m >= n2) {
        return n1 == n2 ? x1 < x2 : n1 < n2;
      }
      return n1 < n2;
    });
    print_vector_v(out, subs);
  }

  void solve(istream& in, ostream& out) {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }

private:
  string s;
  int n;
  vector<pair<int, int>> subs;
};