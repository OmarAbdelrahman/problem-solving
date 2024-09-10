#include <bits/stdc++.h>

using namespace std;

class EmoogleBalance {
public:
  void solve() {
    for (int _ = 0, n; in >> n && n != 0; _++) {
      int r = 0;
      while (n--) {
        int a;
        in >> a;
        if (a) r += 1; else r -= 1;
      }
      print_case(out, _ + 1, r);
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

  EmoogleBalance(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};