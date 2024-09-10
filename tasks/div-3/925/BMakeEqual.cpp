#include <bits/stdc++.h>

#include "../../../library/io.hpp"

using namespace std;
using namespace io;

class BMakeEqual {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int64_t> a(n);
    in >> a;
    int64_t total = accumulate(begin(a), end(a), INT64_C(0));
    int64_t to = total / n;
    int64_t pour = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] >= to) {
        pour += (a[i] - to);
        a[i] = to;
      } else {
        if (pour <= 0) continue;
        int64_t take = to - a[i];
        if (take <= pour) {
          pour -= take;
          a[i] = to;
        } else {
          a[i] = pour;
          pour = 0;
        }
      }
    }
    bool ok = all_of(begin(a), end(a), [&](int v) { return v == to; });
    print_yes_or_no(out, ok);
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  void print_yes_or_no(std::ostream& o, const bool& condition, const bool new_line = true) {
    o << (condition ? "YES" : "NO") << (new_line ? '\n' : char());
  }
  std::string yes_or_no(const bool condition) {
    return condition ? "YES" : "NO";
  }
  template<typename T = std::string>
  T value_conditional(const bool condition, const std::array<T, 2>& options) {
    return options[condition];
  }
  template<typename T = std::string>
  void print_conditional(std::ostream& o, const bool condition, const std::array<T, 2>& options, const bool new_line = true) {
    o << options[condition] << (new_line ? '\n' : char());
  }
  template<typename T>
  void print_case(std::ostream& o, const int case_i, const T& result, const bool new_line = true) {
    o << "Case " << case_i << ": " << result << (new_line ? '\n' : char());
  }

  BMakeEqual(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};