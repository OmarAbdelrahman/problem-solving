#include <bits/stdc++.h>

#include "../../../../library/vector_io.hpp"
using namespace std;

class Battleship {
public:
  void solveOne() {
    int w, h, n;
    in >> w >> h >> n;
    vector<vector<string>> b(2, vector<string>(h));
    in >> b;
    vector<int> cnt(2, 0);
    for (int i = 0; i < 2; i++) {
      for (const string& bi : b[i]) {
        cnt[i] += count(begin(bi), end(bi), '#');
      }
    }
    bool end = false;
    for (int turn = 0; n--; ) {
      int x, y;
      in >> x >> y;
      if (end) continue;
      int r = h - 1 - y;
      int c = x;
      if (b[1 - turn][r][c] == '#') {
        b[1 - turn][r][c] = '_';
        cnt[1 - turn] -= 1;
        if (cnt[1 - turn] == 0) {
          turn = 1 - turn;
        }
      } else {
        turn = 1 - turn;
      }
      if (turn == 0 && cnt[0] * cnt[1] == 0) end = true;
    }
    if (cnt[0] > 0 && cnt[1] == 0)
      out << "player one wins" << '\n';
    else if (cnt[1] > 0 && cnt[0] == 0)
      out << "player two wins" << '\n';
    else
      out << "draw" << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    while (nt--) solveOne();
  }

  Battleship(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};