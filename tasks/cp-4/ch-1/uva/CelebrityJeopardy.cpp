#include <bits/stdc++.h>

using namespace std;

class CelebrityJeopardy {
public:
  void solve() {
    for (string s; getline(in, s); )
      out << s << '\n';
  }

  CelebrityJeopardy(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};