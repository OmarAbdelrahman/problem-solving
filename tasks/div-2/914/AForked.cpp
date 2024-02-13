#include <bits/stdc++.h>

using namespace std;

class AForked {
public:
  void solveOne() {
    int kn, km;
    in >> kn >> km;
    int xk, yk;
    in >> xk >> yk;
    int xq, yq;
    in >> xq >> yq;
    int knight[8][2] = {{-kn, -km}, {-kn, km}, {kn, -km}, {km, kn}, {-km, kn}, {km, -kn}, {kn, km}, {-km, -kn}};
    vector<pair<int, int>> king;
    for (const auto& move : knight) {
      king.emplace_back(xk + move[0], yk + move[1]);
    }
    int result = 0;
    map<pair<int, int>, bool> v;
    for (const auto& move : knight) {
      pair<int, int> queen = {xq + move[0], yq + move[1]};
      for (const auto k_move : king) {
        if (k_move == queen && !v[k_move]) {
          result += 1;
          v[k_move] = true;
          break;
        }
      }
    }
    out << result << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  AForked(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};