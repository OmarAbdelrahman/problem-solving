#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>

template<typename T>
std::istream& operator >> (std::istream& in, std::vector<T>& v) {
  for (auto& vi : v) in >> vi;
  return in;
}

template<typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& v) {
  const int n = static_cast<int>(v.size());
  for (int i = 0; i < n; i++) {
    if (i > 0) out << ' ';
    out << v[i];
  }
  return out;
}

using namespace std;

class suffix_array_t {
public:
  suffix_array_t() = default;

  explicit suffix_array_t(const string& _s) {
    s = _s + DELIM;
    p = vector<int>(size());
    c = vector<int>(size());
    vector<int> count(300, 0);
    for (const char& ch : s) {
      count[ch]++;
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
    for (int k = 0; 1 << k < size(); k++) {
      for (int i = 0; i < size(); i++) {
        p[i] = (p[i] - (1 << k) + size()) % size();
      }
      count = vector<int>(size(), 0);
      for (const int& ci : c) {
        count[ci]++;
      }
      for (int i = 1; i < int(count.size()); i++) {
        count[i] += count[i - 1];
      }
      vector<int> new_p(size());
      for (int i = size() - 1; i >= 0; i--) {
        new_p[--count[c[p[i]]]] = p[i];
      }
      p.swap(new_p);
      vector<int> new_c(size());
      new_c[p[0]] = 0;
      for (int i = 1; i < size(); i++) {
        const int j = i - 1;
        const pair<int, int> rn = {c[p[i]], c[(p[i] + (1 << k)) % size()]};
        const pair<int, int> pv = {c[p[j]], c[(p[j] + (1 << k)) % size()]};
        new_c[p[i]] = new_c[p[j]] + (int) (rn != pv);
      }
      c.swap(new_c);
    }
  }

  [[nodiscard]] inline int size() const {
    return static_cast<int>(s.size());
  }

  int& operator[](const int& at) {
    assert(!p.empty() && at >= 0 && at < size());
    return p[at];
  }

  const int& operator[](const int& at) const {
    assert(!p.empty() && at >= 0 && at < size());
    return p[at];
  }

private:
  vector<int> p, c;
  string s;
  const char DELIM = char(30);
};

void solve(istream& in, ostream& out) {
  for (string s; getline(in, s); in.ignore()) {
    int n;
    in >> n;
    vector<int> a(n);
    in >> a;
    suffix_array_t sa(s);
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
      r[i] = sa[a[i] + 1];
    }
    out << r << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ifstream fin(R"(C:\Users\omara\CLionProjects\problem-solving\kattis\in.txt)");
  istream& in(std::cin);
  ostream& out(std::cout);
  solve(in, out);
  return 0;
}