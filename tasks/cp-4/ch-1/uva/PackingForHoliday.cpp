#include <bits/stdc++.h>

using namespace std;

class PackingForHoliday {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0, a, b, c; _ < nt; _++) {
      out << "Case " << _ + 1 << ": ";
      in >> a >> b >> c;
      print_conditional(out, a <= 20 && b <= 20 && c <= 20, {"bad", "good"});
    }
  }

  template<typename T = std::string>
  void print_conditional(std::ostream& o, const bool condition, const std::array<T, 2>& options, const bool new_line = true) {
    o << options[condition] << (new_line ? '\n' : char());
  }

  PackingForHoliday(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};