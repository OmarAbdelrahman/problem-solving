#include <bits/stdc++.h>

using namespace std;

class RobotInstructions {
public:
  void solve() {
    int nt;
    in >> nt;
    while (nt--) {
      int n;
      in >> n;
      vector<int> d;
      int at = 0;
      while (n--) {
        string s;
        in >> s;
        if (s[0] == 'L') {
          d.push_back(-1);
        } else if (s[0] == 'R') {
          d.push_back(1);
        } else {
          int i;
          in >> s >> i;
          d.push_back(d[i - 1]);
        }
        at += d.back();
      }
      out << at << '\n';
    }
  }

  RobotInstructions(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};