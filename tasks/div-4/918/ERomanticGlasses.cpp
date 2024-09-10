#include <bits/stdc++.h>

#include "../../../library/io.hpp"

using namespace std;
using namespace io;

class ERomanticGlasses {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<int64_t> a(n);
    in >> a;
    vector<int64_t> s(n + 1, 0);
    for (int i = 0; i < n; i++) {
      s[i + 1] = s[i] + (i % 2 == 0 ? a[i] : -a[i]);
    }
    print_yes_or_no(out, size(set<int64_t>(begin(s), end(s))) != n + 1);
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
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

  ERomanticGlasses(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};