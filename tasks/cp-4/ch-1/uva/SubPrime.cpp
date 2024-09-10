#include <bits/stdc++.h>

using namespace std;

class SubPrime {
public:
  void solve() {
    for (int b, n; in >> b >> n && (b != 0 || n != 0); ) {
      vector<int> m(b);
      for (int& mi : m) {
        in >> mi;
      }
      for (int i = 0; i < n; i++) {
        int d, c, v;
        in >> d >> c >> v;
        m[d - 1] -= v;
        m[c - 1] += v;
      }
      print_conditional(out, all_of(begin(m), end(m), [](int x) { return x >= 0; }), {"N", "S"});
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

  SubPrime(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};