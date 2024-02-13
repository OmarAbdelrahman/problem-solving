#include <bits/stdc++.h>

using namespace std;

class Cetiri {
public:
  void solve() {
    int a, b, c;
    in >> a >> b >> c;
    array<int, 3> v = {a, b, c};
    sort(begin(v), end(v));
    if (v[2] - v[1] == v[1] - v[0]) {
      out << v[2] + v[2] - v[1] << '\n';
    } else if (v[2] - v[1] > v[1] - v[0]) {
      out << v[1] + v[1] - v[0] << '\n';
    } else {
      out << v[0] + v[2] - v[1] << '\n';
    }
  }

  Cetiri(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};