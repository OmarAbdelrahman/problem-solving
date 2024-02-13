#include <bits/stdc++.h>

using namespace std;

class CorrectMove {
public:
  struct pos_t {
    int x, y;

    inline bool ok(const int L) const {
      return x >= 0 && x < L && y >= 0 && y < L;
    }
  };

  void moves(pos_t q, pos_t dir, vector<int>& moves) {
    for (int at = 1; at <= M; at++) {
      pos_t nq = {dir.x * at + q.x, dir.y * at + q.y};
      if (nq.ok(M)) {
        if (!empty[nq.x][nq.y]) break;
        moves.push_back(of_board[nq.x][nq.y]);
      }
    }
  }

  void solve() {
    of_board = vector<vector<int>>(M, vector<int>(M));
    on_board = vector<pos_t>(M * M);
    for (int p = 0; p < M * M; p++) {
      int i = p / M;
      int j = p % M;
      of_board[i][j] = p;
      on_board[p] = {i, j};
    }
    for (int k, q, next_q; in >> k >> q >> next_q; ) {
      if (k == q) {
        out << "Illegal state" << '\n';
        continue;
      }
      empty = vector<vector<bool>>(M, vector<bool>(M, true));
      empty[on_board[k].x][on_board[k].y] = false;
      empty[on_board[q].x][on_board[q].y] = false;
      vector<int> legal_moves;
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if ((dx == 0) ^ (dy == 0)) {
            moves(on_board[q], {dx, dy}, legal_moves);
          }
        }
      }
      if (find(begin(legal_moves), end(legal_moves), next_q) == end(legal_moves)) {
        out << "Illegal move" << '\n';
        continue;
      }
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if ((dx == 0) ^ (dy == 0)) {
            pos_t nk = {on_board[k].x + dx, on_board[k].y + dy};
            if (nk.ok(M)) {
              empty[nk.x][nk.y] = false;
            }
          }
        }
      }
      if (!empty[on_board[next_q].x][on_board[next_q].y]) {
        out << "Move not allowed" << '\n';
        continue;
      }
      empty[on_board[k].x][on_board[k].y] = true;
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          pos_t nk = {on_board[k].x + dx, on_board[k].y + dy};
          if (nk.ok(M)) {
            empty[nk.x][nk.y] = true;
          }
        }
      }
      legal_moves.clear();
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if ((dx == 0) ^ (dy == 0)) {
            moves(on_board[next_q], {dx, dy}, legal_moves);
          }
        }
      }
      bool stop = true;
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if ((dx == 0) ^ (dy == 0)) {
            pos_t nk = {on_board[k].x + dx, on_board[k].y + dy};
            if (nk.ok(M) && count(begin(legal_moves), end(legal_moves), of_board[nk.x][nk.y]) == 0) {
              stop = false;
            }
          }
        }
      }
      out << (stop ? "Stop" : "Continue") << '\n';
    }
  }

  CorrectMove(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  vector<vector<bool>> empty;
  vector<vector<int>> of_board;
  vector<pos_t> on_board;

  const int M = 8;
};