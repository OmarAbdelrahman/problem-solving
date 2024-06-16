#include <bits/stdc++.h>
#include "../../../library/pair_utils.hpp"
#include "../../../library/vector_utils.hpp"
using namespace std;

class DThreeActivities {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<vector<int64_t>> costs(M, vector<int64_t>(n));
    in >> costs;
    vector<vector<int>> perm(M, vector<int>(n));
    for (int i = 0; i < M; i++) {
      iota(begin(perm[i]), end(perm[i]), 0);
      sort(begin(perm[i]), end(perm[i]), [&](int a, int b) { return costs[i][a] > costs[i][b]; });
    }
    int64_t result = numeric_limits<int64_t>::min();
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < M; j++) {
        for (int k = 0; k < M; k++) {
          int a = perm[0][i], b = perm[1][j], c = perm[2][k];
          if (a == b || b == c || a == c) continue;
          result = max(result, costs[0][a] + costs[1][b] + costs[2][c]);
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

  DThreeActivities(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int M = 3;
};