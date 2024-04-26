#include <bits/stdc++.h>

using namespace std;

class RockPaperScissorsTournament {
public:
  void solve() {
    for (int _ = 0, n, k; in >> n >> k && n; _++) {
      if (_) out << '\n';
      vector<array<int, 2>> stats(n + 1, {0, 0});
      k = k * n * (n - 1) / 2;
      while (k--) {
        int p1, p2;
        string m1, m2;
        in >> p1 >> m1 >> p2 >> m2;
        int winner = get(p1, p2, m1[0], m2[0]);
        if (winner == -1) continue;
        stats[winner][W] += 1;
        stats[winner == p1 ? p2 : p1][L] += 1;
      }
      for (int i = 1; i < n + 1; i++) {
        const array<int, 2>& stat = stats[i];
        if (stat[0] + stat[1] == 0) {
          out << "-" << '\n';
          continue;
        }
        double r = stat[0] * 1.0 / (stat[0] + stat[1]) * 1.0;
        out << fixed << setprecision(3) << r << '\n';
      }
    }
  }

  inline int get(int p1, int p2, char m1, char m2) {
    if (m1 == m2) return -1;
    if (m1 == R) return m2 == S ? p1 : p2;
    if (m1 == P) return m2 == R ? p1 : p2;
    return m2 == P ? p1 : p2;
  }

  RockPaperScissorsTournament(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int W = 0;
  const int L = 1;

  const char R = 'r';
  const char P = 'p';
  const char S = 's';
};