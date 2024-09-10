#include <bits/stdc++.h>

using namespace std;

class IsItHalloweencom {
public:
  void solve() {
    string s;
    int n;
    in >> s >> n;
    print_conditional(out, (s == "OCT" && n == 31) || (s == "DEC" && n == 25), {"nope", "yup"});
  }

  template<typename T = std::string>
  void print_conditional(std::ostream& o, const bool condition, const std::array<T, 2>& options, const bool new_line = true) {
    o << options[condition] << (new_line ? '\n' : char());
  }

  IsItHalloweencom(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};