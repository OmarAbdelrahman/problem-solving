#include <bits/stdc++.h>
using namespace std;

class suffix_array {
public:
  suffix_array() = default;

  explicit suffix_array(const string& _s) {
    initialize(_s);
  }

  string longest_common_substring(const string& a, const string& b) {
    initialize(a + char(DELIM - 1) + b);
    auto belong_to_different_strings = [&](const int ai, const int bi) -> bool {
      const int an = int(a.size());
      return (ai <= an) != (bi <= an);
    };
    string r;
    int r_size = -1;
    for (int i = 1; i < size(); i++) {
      if (belong_to_different_strings(p[i], p[i - 1]) && lcp[i] > r_size) {
        r_size = lcp[i];
        r = s.substr(p[i], r_size);
      }
    }
    return r;
  }

  int find_first_of(const string& substring) {
    const int m = int(substring.size());
    int l = 0, r = size() - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      int value = strncmp(s.c_str() + p[mid], substring.c_str(), m);
      if (value >= 0) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    if (strncmp(s.c_str() + p[l], substring.c_str(), m) != 0) {
      return -1;
    }
    return l;
  }

  pair<int, int> find_interval_of(const string& substring) {
    const int i = find_first_of(substring);
    if (i == -1) {
      return {-1, -1};
    }
    const int m = int(substring.size());
    int l = 0, r = size() - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      int value = strncmp(s.c_str() + p[mid], substring.c_str(), m);
      if (value > 0) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    if (strncmp(s.c_str() + p[r], substring.c_str(), m) != 0) {
      return {i, r - 1};
    }
    return {i, r};
  }

  int occurrences_of(const string& substring) {
    const pair<int, int> interval = find_interval_of(substring);
    if (interval.first == -1) return 0;
    return interval.second - interval.first + 1;
  }

  int64_t count_different_substrings() {
    assert(!p.empty() || !lcp.empty());
    int64_t count = 0;
    for (int i = 1; i < size(); i++) {
      count += (int64_t) size() - 1 - p[i] - lcp[i - 1];
    }
    return count;
  }

  [[nodiscard]] inline const vector<int>& _lcp() const {
    assert(!lcp.empty());
    return lcp;
  }

  [[nodiscard]] inline const vector<int>& _c() const {
    assert(!c.empty());
    return c;
  }

  [[nodiscard]] inline const vector<int>& _p() const {
    assert(!p.empty());
    return p;
  }

  [[nodiscard]] inline int size() const {
    return int(s.size());
  }

private:
  void initialize(const string& _s) {
    s = _s + DELIM;
    p = vector<int>(size());
    c = vector<int>(size());
    vector<int> count(300, 0);
    for (const char& si: s) {
      count[si]++;
    }
    for (int i = 1; i < int(count.size()); i++) {
      count[i] += count[i - 1];
    }
    for (int i = size() - 1; i >= 0; i--) {
      p[--count[s[i]]] = i;
    }
    c[p[0]] = 0;
    for (int i = 1; i < size(); i++) {
      c[p[i]] = c[p[i - 1]] + (int) (s[p[i]] != s[p[i - 1]]);
    }
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
        const pair<int, int> rn = { c[p[i]], c[(p[i] + (1 << k)) % size()] };
        const pair<int, int> pr = { c[p[j]], c[(p[j] + (1 << k)) % size()] };
        new_c[p[i]] = new_c[p[i - 1]] + (int) (rn != pr);
      }
      c.swap(new_c);
    }
  }

  void build_lcp() {
    assert(!c.empty() || !p.empty() || !s.empty());
    lcp = vector<int>(size());
    int k = 0;
    for (int i = 0; i < int(lcp.size()); i++) {
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

template <typename T, class F = std::function<T(const T&, const T&)>>
class sparse_table {
public:
  sparse_table(const std::vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(const int& from, const int& to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }

private:
  int n;
  std::vector<std::vector<T>> mat;
  F func;
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
    const vector<int>& c = sa._c();
    sparse_table<int> spt(sa._lcp(), [&](const int& a, const int& b) -> int { return min(a, b); });
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
      int lcp_m = spt.get(i + (int) (i != j), j);
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