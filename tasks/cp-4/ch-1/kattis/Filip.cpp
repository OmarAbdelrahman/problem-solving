#include <bits/stdc++.h>
using namespace std;

class Filip {
public:
  void solve() {
    string a, b;
    in >> a >> b;
    reverse(begin(a), end(a));
    reverse(begin(b), end(b));
    print_conditional(out, a > b, {b, a});
  }

  template<typename T = std::string>
  void print_conditional(std::ostream& o, const bool condition, const std::array<T, 2>& options, const bool new_line = true) {
    o << options[condition] << (new_line ? '\n' : char());
  }

  Filip(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};