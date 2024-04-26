#include <bits/stdc++.h>

using namespace std;

class GameRank {
public:
  void solve() {
    string turns;
    in >> turns;
    const int n = size(turns);
    int stars = turns[0] == W;
    int ws = 1;
    int rank = 25;
    for (int at = 1; at < n; at++) {
      if (turns[at] == W) {
        if (turns[at - 1] == W) ws += 1; else ws = 1;
        stars += 1;
      } else {
        ws = 1;
        if (rank <= 20) {
          stars -= 1;
          if (stars < 0) {
            rank += 1;
            if (rank > 20) {
              rank = 20;
              stars = 0;
            } else if (rank >= 16) {
              stars = 2;
            } else if (rank >= 11) {
              stars = 3;
            } else if (rank > 1) {
              stars = 4;
            }
          }
        }
      }
      if (ws >= 3 && rank >= 6) {
        stars += 1;
      }
      adjust(rank, stars);
    }
    out << rank << '\n';
  }

  void adjust(int& rank, int& stars) {
    if (rank >= 21 && stars > 2) {
      rank -= 1;
      stars -= 2;
    } else if (rank >= 16 && stars > 3) {
      rank -= 1;
      stars -= 3;
    } else if (rank >= 11 && stars > 4) {
      rank -= 1;
      stars -= 4;
    } else if (rank >= 1 && stars > 5) {
      if (rank == 1) {
        out << "Legend" << '\n';
        exit(0);
      } else {
        rank -= 1;
        stars -= 5;
      }
    }
  }

  GameRank(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const char W = 'W';
};