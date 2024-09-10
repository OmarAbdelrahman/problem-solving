#include <bits/stdc++.h>

using namespace std;

class AWalletExchange {
public:
  void solveOne() {
    int a, b;
    in >> a >> b;
    print_conditional(out, abs(b - a) % 2 == 0, {"Alice", "Bob"});
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  template<typename T = std::string>
  void print_conditional(std::ostream& o, const bool condition, const std::array<T, 2>& options, const bool new_line = true) {
    o << options[condition] << (new_line ? '\n' : char());
  }

  AWalletExchange(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};