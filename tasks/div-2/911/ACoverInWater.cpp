#include <bits/stdc++.h>

using namespace std;

class ACoverInWater {
public:
  void solveOne() {
    int n;
    in >> n;
    string s;
    in >> s;
    if (s.find("...") != string::npos) {
      out << "2\n";
    } else {
      out << count(begin(s), end(s), '.') << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  ACoverInWater(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};