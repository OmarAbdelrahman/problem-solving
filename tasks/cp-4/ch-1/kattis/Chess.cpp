#include <bits/stdc++.h>

#include "../../../../library/pair_io.hpp"
#include "../../../../library/vector_io.hpp"
using namespace std;


class Chess {
public:
  struct pos_t {
    int x, y;

    inline int tile_color() {
      return abs(x - y) % 2;
    }

    inline pair<char, int> tile() const {
      return {x + 'A', y + 1};
    }

    inline bool inside() const {
      return x >= 0 && x < Chess::M & y >= 0 && y < Chess::M;
    }

    inline bool operator == (const pos_t& other) const {
      return x == other.x && y == other.y;
    }

    friend ostream& operator << (ostream& o, const pos_t& p) {
      return o << '(' << p.x << ", " << p.y << ')';
    }
  };

  void solve() {
    int nt;
    in >> nt;
    while (nt--) {
      char b1, b2;
      int y1, y2;
      in >> b1 >> y1 >> b2 >> y2;
      pos_t a = {b1 - 'A', y1 - 1};
      pos_t b = {b2 - 'A', y2 - 1};
      if (a.tile_color() ^ b.tile_color()) {
        out << "Impossible" << '\n';
        continue;
      }
      vector<vector<bool>> empty(M, vector<bool>(M, true));
      queue<pair<pos_t, vector<pos_t>>> q;
      for (q.push({a, {}}); !q.empty(); q.pop()) {
        auto [p, moves] = q.front();
        if (!empty[p.x][p.y] || size(moves) > M) continue;
        empty[p.x][p.y] = false;
        moves.push_back(p);
        if (p == b) {
          out << size(moves) - 1;
          for (const pos_t& move : moves) {
            out << ' ' << move.tile();
          }
          out << '\n';
          break;
        }
        for (int step = 1; step <= M; step++) {
          for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
              if (dx != 0 && dy != 0) {
                pos_t np = {dx * step + p.x, dy * step + p.y};
                if (np.inside()) {
                  q.emplace(np, moves);
                }
              }
            }
          }
        }
      }
    }
  }

  Chess(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  static const int MOVES = 3;
  static const int M = 8;
};