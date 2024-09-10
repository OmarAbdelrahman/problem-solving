#include <bits/stdc++.h>

using namespace std;

class BitsEqualizer {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      string s, t;
      in >> s >> t;
      const int n = s.size();
      int s1 = 0, t1 = 0, qs = 0;
      int tf = 0, ft = 0;
      for (int i = 0; i < n; i++) {
        s1 += s[i] == '1';
        t1 += t[i] == '1';
        qs += s[i] == '?';
        if (s[i] != t[i]) {
          tf += s[i] == '1';
          ft += s[i] == '0';
        }
      }
      print_case(out, _, value_conditional<int>(s1 > t1, {qs + max(tf, ft), -1}));
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

  BitsEqualizer(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};