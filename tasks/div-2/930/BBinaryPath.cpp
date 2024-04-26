#include <bits/stdc++.h>

using namespace std;

class BBinaryPath {
public:
  void solveOne() {
    int n;
    in >> n;
    string s1, s2;
    in >> s1 >> s2;
    string path;
    int checkpoint = -1;
    for (int i = 0; i < n; i++) {
      if (i + 1 == n || s1[i + 1] > s2[i]) {
        path = s1.substr(0, i + 1) + s2.substr(i);
        checkpoint = i - 1;
        break;
      }
    }
    int i = checkpoint, count = 1;
    while (i >= 0 && s1[i + 1] == s2[i]) {
      count += 1;
      i -= 1;
    }
    out << path << '\n';
    out << count << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  BBinaryPath(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};