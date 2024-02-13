#include <bits/stdc++.h>

using namespace std;

class TheLastProblem {
public:
  void solve() {
    string s;
    getline(in, s);
    out << "Thank you, " << s << ", and farewell!" << '\n';
  }

  TheLastProblem(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};