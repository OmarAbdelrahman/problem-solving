#include <bits/stdc++.h>

using namespace std;

class PeaSoupAndPancakes {
public:
  void solve() {
    int n;
    in >> n;
    string r;
    while (n--) {
      int m;
      in >> m;
      in.ignore();
      string name;
      getline(in, name);
      bool pan = false, pea = false;
      while (m--) {
        string s;
        getline(in, s);
        pan |= s == "pancakes";
        pea |= s == "pea soup";
      }
      if (pan && pea && r.empty()) {
        r = name;
      }
    }
    print_conditional(out, r.empty(), {r, "Anywhere is fine I guess"});
  }

  template<typename T = std::string>
  void print_conditional(std::ostream& o, const bool condition, const std::array<T, 2>& options, const bool new_line = true) {
    o << options[condition] << (new_line ? '\n' : char());
  }

  PeaSoupAndPancakes(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};