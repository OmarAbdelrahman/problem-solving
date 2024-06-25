#include <iostream>
#include <string>
#include <array>

class MasteringMastermind {
public:
  inline int f(const char ch) const {
    return ch - 'A';
  }

  void solve() {
    int n;
    std::string a, g;
    in >> n >> a >> g;
    int r = 0;
    std::array<int, 26> a_count{}, g_count{};
    for (int i = 0; i < n; i++) {
      if (a[i] == g[i]) {
        r += 1;
      } else {
        a_count[f(a[i])] += 1;
        g_count[f(g[i])] += 1;
      }
    }
    int s = 0;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
      const int at = f(ch);
      s += std::min(a_count[at], g_count[at]);
    }
    out << r << ' ' << s << '\n';
  }

  MasteringMastermind(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};