#include <bits/stdc++.h>
using namespace std;

#define _size(a) (int) (a).size()

struct suffix_array {

  suffix_array() = default;

  explicit suffix_array(const string& _s) {
    initialize(_s);
    build();
    build_lcp();
  }

  void build() {
    for (int k = 0; 1 << k < size(); k++) {
      for (int i = 0; i < size(); i++) {
        p[i] = (p[i] - (1 << k) + size()) % size();
      }
      count_sort();
      vector<int> new_c(size());
      new_c[p[0]] = 0;
      for (int i = 1; i < size(); i++) {
        const int j = i - 1;
        pair<int, int> rn = {c[p[i]], c[(p[i] + (1 << k)) % size()]};
        pair<int, int> pr = {c[p[j]], c[(p[j] + (1 << k)) % size()]};
        new_c[p[i]] = new_c[p[i - 1]] + (int) (rn != pr);
      }
      c.swap(new_c);
    }
  }

  void build_lcp() {
    assert(!c.empty() || !p.empty() || !s.empty());
    lcp = vector<int>(size());
    int k = 0;
    for (int i = 0; i < _size(lcp); i++) {
      int pi = c[i];
      if (pi == 0) continue;
      int j = p[pi - 1];
      while (s[i + k] == s[j + k]) {
        k++;
      }
      lcp[pi] = k;
      k = max(k - 1, 0);
    }
  }

  const vector<int>& get_lcp() const {
    assert(!lcp.empty());
    return lcp;
  }

  const vector<int>& get_c() const {
    assert(!c.empty());
    return c;
  }

  int size() const {
    return int(s.size());
  }

private:
  void initialize(const string &_s) {
    s = _s + DELIM;
    p = vector<int>(size());
    c = vector<int>(size());
    vector<int> count(300, 0);
    for (const char& si: s) {
      count[si]++;
    }
    for (int i = 1; i < _size(count); i++) {
      count[i] += count[i - 1];
    }
    for (int i = size() - 1; i >= 0; i--) {
      p[--count[s[i]]] = i;
    }
    c[p[0]] = 0;
    for (int i = 1; i < size(); i++) {
      c[p[i]] = c[p[i - 1]] + (int) (s[p[i]] != s[p[i - 1]]);
    }
  }

  void count_sort() {
    vector<int> count(size(), 0);
    for (const int& ci: c) {
      count[ci]++;
    }
    for (int i = 1; i < size(); i++) {
      count[i] += count[i - 1];
    }
    vector<int> new_p(size());
    for (int i = size() - 1; i >= 0; i--) {
      new_p[--count[c[p[i]]]] = p[i];
    }
    p.swap(new_p);
  }

  vector<int> lcp;
  vector<int> p, c;
  string s;

  const char DELIM = char(31);
};

struct sparse_table {
  sparse_table() = default;

  explicit sparse_table(const vector<int>& _a) {
    a = _a;
    const int n = _size(a);
    const int lgn = (int) log2(n) + 1;
    lg2 = vector<int>(1 << lgn, 0);
    for (int i = 0; i < lgn; i++) {
      lg2[1 << i] = i;
    }
    for (int i = 2; i < _size(lg2); i++) {
      if (lg2[i] == 0) {
        lg2[i] = lg2[i - 1];
      }
    }
    dp = vector<vector<int>>(lgn + 1, vector<int>(n));
    dp[0] = a;
    for (int i = 1; 1 << i <= n; ++i) {
      for (int j = 0; j + (1 << i) - 1 < n; ++j) {
        int x = dp[i - 1][j];
        int y = dp[i - 1][j + (1 << (i - 1))];
        dp[i][j] = min(x, y);
      }
    }
  }

  int rmq(const int i, const int j) {
    int k = lg2[j - i + 1];
    int x = dp[k][i];
    int y = dp[k][j - (1 << k) + 1];
    return min(x, y);
  }

private:
  vector<int> a, lg2;
  vector<vector<int>> dp;
};

class CSortingSubstrings {
public:
  void solveOne(istream& in, ostream& out) {
    in >> s;
    in >> n;
    subs = vector<pair<int, int>>(n);
    for (auto& [x, y] : subs) {
      in >> x >> y;
      --x;
      --y;
    }
    suffix_array sa(s);
    const vector<int>& c = sa.get_c();
    sparse_table spt(sa.get_lcp());
    sort(begin(subs), end(subs), [&](const auto& p1, const auto& p2) -> bool {
      auto [x1, y1] = p1;
      auto [x2, y2] = p2;
      if (x1 == x2) {
        return y1 < y2;
      }
      int n1 = y1 - x1 + 1;
      int n2 = y2 - x2 + 1;
      int i = min(c[x1], c[x2]);
      int j = max(c[x1], c[x2]);
      int lcp_m = spt.rmq(i + (int) (i != j), j);
      if (lcp_m < n1 && lcp_m < n2) {
        return c[x1] < c[x2];
      }
      if (lcp_m >= n1 && lcp_m >= n2) {
        return n1 == n2 ? x1 < x2 : n1 < n2;
      }
      return n1 < n2;
    });
    for (const auto& [x, y] : subs) {
      out << x + 1 << ' ' << y + 1 << '\n';
    }
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