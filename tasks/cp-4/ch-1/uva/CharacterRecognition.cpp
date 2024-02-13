#include <bits/stdc++.h>

using namespace std;

class CharacterRecognition {
public:
  void solve() {
    int nt;
    in >> nt;
    vector<string> g(RS);
    for (string& s : g) {
      in >> s;
    }
    for (int i = 0; i < nt; i++) {
      int at = i * 4;
      if (g[0].substr(at, N) == ".*.") {
        out << 1;
      } else if (g[3].substr(at, N) == "*..") {
        out << 2;
      } else {
        out << 3;
      }
    }
    out << '\n';
  }

  CharacterRecognition(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int RS = 5;
  const int N = 3;
};