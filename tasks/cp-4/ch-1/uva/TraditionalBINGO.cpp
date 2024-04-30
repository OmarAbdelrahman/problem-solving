#include <bits/stdc++.h>

using namespace std;

class TraditionalBINGO {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      vector<vector<int>> cards(N, vector<int>(N, -1));
      vector<array<int, 2>> ids(T + 1, {-1, -1});
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (i == 2 && j == 2) continue;
          in >> cards[i][j];
          ids[cards[i][j]] = {i, j};
        }
      }
      vector<int> row(N, 0), col(N, 0);
      int d1 = 1, d2 = 1;
      row[2] = 1;
      col[2] = 1;
      auto bing = [&](const int card) -> bool {
        const array<int, 2> p = ids[card];
        if (p[0] == p[1]) d1 += 1;
        if (p[0] == N - p[1] - 1) d2 += 1;
        if (d1 == N || d2 == N)
          return true;
        row[p[0]] += 1;
        col[p[1]] += 1;
        return row[p[0]] == N || col[p[1]] == N;
      };
      int r = -1;
      for (int i = 0; i < T; i++) {
        int card;
        in >> card;
        if (ids[card][0] == -1) continue;
        cards[ids[card][0]][ids[card][1]] = -1;
        if (bing(card) && r == -1) {
          r = i + 1;
        }
      }
      if (r != -1) out << "BINGO after " << r << " numbers announced" << '\n';
    }
  }

  inline bool bingo(const vector<vector<int>>& cards) {
    bool ok = true;
    for (int i = 0; i < N; i++)
      ok &= cards[i][i] == -1;
    if (ok) return true;
    ok = true;
    for (int i = 0; i < N; i++)
      ok &= cards[i][N - i - 1] == -1;
    if (ok) return true;
    for (int i = 0; i < N; i++) {
      ok = true;
      for (int j = 0; j < N; j++)
        ok &= cards[i][j] == -1;
      if (ok) return true;
      ok = true;
      for (int j = 0; j < N; j++)
        ok &= cards[j][i] == -1;
      if (ok) return true;
    }
    return ok;
  }

  TraditionalBINGO(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int N = 5;
  const int T = 75;
};