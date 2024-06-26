/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author omar-abdelrahman
 */

#include <bits/stdc++.h>

template<typename T>
std::istream& operator >> (std::istream& in, std::vector<T>& v) {
  for (auto& it : v) in >> it;
  return in;
}

template<typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& v) {
  const uint32_t n = std::size(v);
  for (int i = 0; i < n; i++) {
    if (i > 0) out << ' ';
    out << v[i];
  }
  return out;
}

template<typename T_vector>
void print_vector_h(std::ostream& out, const T_vector& v, const bool& new_line = true) {
  const uint32_t n = std::size(v);
  for (int i = 0; i < n; i++) {
    if (i > 0) out << ' ';
    out << v[i];
  }
  if (new_line) out << '\n';
}

template<typename T_vector>
void print_vector_v(std::ostream& out, const T_vector& v, const bool& new_line = true) {
  const uint32_t n = std::size(v);
  for (int i = 0; i < n; i++) {
    out << v[i] << '\n';
  }
  if (new_line) out << '\n';
}

template <class T, std::size_t size = std::tuple_size<T>::value>
std::string to_debug(T, std::string s = "") requires(not std::ranges::range<T>);

std::string to_debug(const auto& x) requires requires(std::ostream& os) { os << x; } {
  return static_cast<std::ostringstream>(std::ostringstream() << x).str();
}

std::string to_debug(std::ranges::range auto& x, std::string s = "") requires(not std::is_same_v<decltype(x), std::string>) {
  for (const auto& xi : x) s += ", " + to_debug(xi);
  return "[" + s.substr(s.empty() ? 0 : 2) + "]";
}

template <class T, std::size_t size>
std::string to_debug(T x, std::string s) requires(not std::ranges::range<T>) {
  [&]<std::size_t... I>(std::index_sequence<I...>) { ((s += ", " + to_debug(std::get<I>(x))), ...); }(std::make_index_sequence<size>());
  return "(" + s.substr(s.empty() ? 0 : 2) + ")";
}

#define debug(...) cerr << __FILE__ ":" << __LINE__ << ": (" #__VA_ARGS__ ") = " << to_debug(tuple(__VA_ARGS__)) << "\n"

using namespace std;

class BEqualize {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int64_t> a(n), p(n), pv(n), pi(n, -1);
    in >> a;
    iota(begin(p), end(p), 1);
    for (int i = 0; i < n; i++) {
      pv[p[i] - 1] = n - i;
    }
    ranges::sort(a, greater{});
    set<int64_t> is_p;
    for (int i = 0; i < n; i++) {
      const int64_t ai = a[i];
      if (ai >= 1 && ai <= n && !is_p.contains(ai)) {
        is_p.insert(ai);
        pi[i] = pv[ai - 1];
      }
    }
    unordered_map<int64_t, int64_t> next;
    int e = 1;
    for (int i = 0; i < n; i++) {
      if (pi[i] != -1) {
        next[a[i]] = pi[i] - 1;
      } else {
        if (is_p.contains(a[i])) {
          pi[i] = next[a[i]];
          next[a[i]] = pi[i] - 1;
        } else {
          while (is_p.contains(e)) {
            e += 1;
          }
          pi[i] = e;
          e += 1;
        }
      }
    }
    vector<int64_t> s(n);
    for (int i = 0; i < n; i++) {
      s[i] = a[i] + pi[i];
    }
    unordered_map<int64_t, int> count;
    for (const int64_t& si : s) {
      count[si] += 1;
    }
    debug(count);
    int r = 0;
    for (const auto& [_, c] : count) {
      r = max(r, c);
    }
    out << r << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  BEqualize(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  BEqualize solver(cin, cout);
  solver.solve();
  return 0;
}
