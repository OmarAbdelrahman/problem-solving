#include <bits/stdc++.h>

using namespace std;

class HelpAPhDCandidateOut {
public:
  void solve() {
    int nt;
    in >> nt;
    while (nt--) {
      string s;
      in >> s;
      size_t p = s.find('+');
      if (p != string::npos) {
        out << stoi(s.substr(0, p)) + stoi(s.substr(p + 1)) << '\n';
      } else {
        out << "skipped" << '\n';
      }
    }
  }

  HelpAPhDCandidateOut(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};