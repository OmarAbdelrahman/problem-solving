#include <bits/stdc++.h>

using namespace std;

class AHulk {
public:
  void solveOne() {
    int n;
    in >> n;
    array<string, 2> feelings = {" that I love", " that I hate"};
    string feeling;
    for (int i = 2; i <= n; i++) {
      feeling += feelings[i % 2];
    }
    out << "I hate" + feeling + " it" << '\n';
  }

  void solve() {
    int nt = 1;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AHulk(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};