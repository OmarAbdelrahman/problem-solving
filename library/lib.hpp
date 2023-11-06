#include <bits/stdc++.h>
using namespace std;

template<typename U, typename V>
ostream& operator << (ostream& out, const pair<U, V>& p) {
  out << '{' << p.first << ", " << p.second << '}';
  return out;
}

template<typename T_vector>
void output_vector(ostream& out, const T_vector& v, bool add_one = false, int s = -1, int e = -1) {
  if (s < 0) s = 0;
  if (e < 0) e = int(v.size());
  for (int i = s; i < e; i++) {
    out << v[i] + (add_one ? 1 : 0) << (i < e - 1 ? ' ' : '\n');
  }
}

struct suffix_array {
  suffix_array() = default;

  explicit suffix_array(const string& _s) {
    initialize(_s);
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
    const int n = int(a.size());
    const int lgn = int(log2(n)) + 1;
    lg2 = vector<int>(1 << lgn, 0);
    for (int i = 0; i < lgn; i++) {
      lg2[1 << i] = i;
    }
    for (int i = 2; i < int(lg2.size()); i++) {
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