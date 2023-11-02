#include <bits/stdc++.h>
using namespace std;

class ASuffixArray1 {
public:
  struct suffix {
    int index;
    pair<int, int> rank;

    suffix(): index(-1), rank({}) { }

    suffix(const int i, const pair<int, int>& r): index(i), rank(r) { }

    bool operator < (const suffix& o) const {
      return rank < o.rank;
    }
  };

  vector<int> suffix_array(const string& s) {
    int n = (int) s.size();
    int m = n;
    while ((m & (m - 1)) != 0) {
      m++;
    }
    vector<suffix> sa(n);
    vector<vector<int>> rank(1, vector<int>(n));
    for (int i = 0; i < n; i++) {
      rank[0][i] = s[i] - '.';
    }
    for (int k = 1; 1 << k <= m; k++) {
      rank.emplace_back(n);
      for (int i = 0; i < n; i++) {
        sa[i] = suffix(i, { rank[k - 1][i], rank[k - 1][(i + (1 << (k - 1))) % n] });
      }
      sort(begin(sa), end(sa));
      rank[k][sa[0].index] = 0;
      for (int i = 1; i < n; i++) {
        rank[k][sa[i].index] = sa[i].rank == sa[i - 1].rank ? rank[k][sa[i - 1].index] : i;
      }
    }
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
      r[i] = sa[i].index;
    }
    return r;
  }

  void solveOne(istream &is, ostream &os) {
    string s; is >> s;
    vector<int> sa = suffix_array(s + "$");
    for (int i = 0; i < (int) sa.size(); i++) {
      os << sa[i] << " \n"[i == (int) sa.size() - 1];
    }
  }

  void solve(istream &is, ostream &os) {
    solveOne(is, os);
  }
};