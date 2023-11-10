#include "string"
#include "vector"

class suffix_array_t {
public:
  suffix_array_t() = default;

  explicit suffix_array_t(const std::string& _s) {
    initialize(_s);
  }

  std::string longest_common_substring(const std::string& a, const std::string& b) {
    initialize(a + char(DELIM - 1) + b);
    auto belong_to_different_strings = [&](const int ai, const int bi) -> bool {
      const int an = static_cast<int>(a.size());
      return (ai <= an) != (bi <= an);
    };
    std::string r;
    int r_size = -1;
    for (int i = 1; i < size(); i++) {
      if (belong_to_different_strings(p[i], p[i - 1]) && lcp[i] > r_size) {
        r_size = lcp[i];
        r = s.substr(p[i], r_size);
      }
    }
    return r;
  }

  int find_first_of(const std::string& substring) {
    const int m = static_cast<int>(substring.size());
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

  std::pair<int, int> find_interval_of(const std::string& substring) {
    const int i = find_first_of(substring);
    if (i == -1) {
      return {-1, -1};
    }
    const int m = static_cast<int>(substring.size());
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

  int occurrences_of(const std::string& substring) {
    const std::pair<int, int> interval = find_interval_of(substring);
    if (interval.first == -1) return 0;
    return interval.second - interval.first + 1;
  }

  int64_t count_distinct_substrings() {
    assert(!p.empty() || !lcp.empty());
    int64_t count = 0;
    for (int i = 1; i < size(); i++) {
      count += (int64_t) size() - 1 - p[i] - lcp[i];
    }
    return count;
  }

  inline std::string suffix(const int& at) {
    assert(!p.empty());
    return s.substr(p[at]);
  }

  inline int suffix_pos(const int& at) const {
    assert(!c.empty());
    return c[at];
  }

  [[nodiscard]] inline const std::vector<int>& _lcp() const { return lcp; }
  [[nodiscard]] inline const std::vector<int>& _c() const { return c; }
  [[nodiscard]] inline const std::vector<int>& _p() const { return p; }
  [[nodiscard]] inline int size() const { return static_cast<int>(s.size()); }

  int& operator[](const int& at) {
    assert(!p.empty() && at >= 0 && at < size());
    return p[at];
  }

  const int& operator[](const int& at) const {
    assert(!p.empty() && at >= 0 && at < size());
    return p[at];
  }

private:
  void initialize(const std::string& _s) {
    s = _s + DELIM;
    p = std::vector<int>(size());
    c = std::vector<int>(size());
    std::vector<int> count(300, 0);
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
      std::vector<int> new_c(size());
      new_c[p[0]] = 0;
      for (int i = 1; i < size(); i++) {
        const int j = i - 1;
        const std::pair<int, int> rn = { c[p[i]], c[(p[i] + (1 << k)) % size()] };
        const std::pair<int, int> pr = { c[p[j]], c[(p[j] + (1 << k)) % size()] };
        new_c[p[i]] = new_c[p[i - 1]] + (int) (rn != pr);
      }
      c.swap(new_c);
    }
  }

  void build_lcp() {
    assert(!c.empty() || !p.empty());
    lcp = std::vector<int>(size());
    int k = 0;
    for (int i = 0; i < int(lcp.size()); i++) {
      int pi = c[i];
      if (pi == 0) continue;
      int j = p[pi - 1];
      while (s[i + k] == s[j + k]) {
        k++;
      }
      lcp[pi] = k;
      k = std::max(k - 1, 0);
    }
  }

  void count_sort() {
    std::vector<int> count(size(), 0);
    for (const int& ci: c) {
      count[ci]++;
    }
    for (int i = 1; i < size(); i++) {
      count[i] += count[i - 1];
    }
    std::vector<int> new_p(size());
    for (int i = size() - 1; i >= 0; i--) {
      new_p[--count[c[p[i]]]] = p[i];
    }
    p.swap(new_p);
  }

  std::vector<int> lcp;
  std::vector<int> p, c;
  std::string s;

  const char DELIM = char(31);
};