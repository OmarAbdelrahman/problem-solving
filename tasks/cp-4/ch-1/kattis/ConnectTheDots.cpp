#include <bits/stdc++.h>

using namespace std;

class ConnectTheDots {
public:
  void solve() {
    for (string row; getline(in, row); )
      if (row.empty()) {
        connect();
        out << '\n';
        board.clear();
      } else {
        board.push_back(row);
      }

    connect();
  }

  void connect() {
    const int n = size(board);
    const int m = size(board.front());
    unordered_map<char, array<int, 2>> pos;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ok(board[i][j])) {
          pos[board[i][j]] = {i, j};
        }
      }
    }
    for (int i = 1; i < size(turn); i++) {
      if (pos.find(turn[i - 1]) == end(pos))
        break;
      if (pos.find(turn[i]) == end(pos))
        break;

      auto p1 = pos[turn[i - 1]];
      auto p2 = pos[turn[i]];
      if (p1[0] == p2[0]) {
        for (int at = min(p1[1], p2[1]); at <= max(p1[1], p2[1]); at++) {
          horizontal(p1[0], at);
        }
      } else if (p1[1] == p2[1]) {
        for (int at = min(p1[0], p2[0]); at <= max(p1[0], p2[0]); at++) {
          vertical(at, p1[1]);
        }
      }
    }
    for (const auto& row : board) {
      out << row << '\n';
    }
  }

  void horizontal(const int i, const int j) {
    char& what = board[i][j];
    if (ok(what)) return;
    if (what == '|') what = '+';
    if (what == '.') what = '-';
  }

  void vertical(const int i, const int j) {
    char& what = board[i][j];
    if (ok(what)) return;
    if (what == '-') what = '+';
    if (what == '.') what = '|';
  }

  static inline bool ok(const char& ch) {
    return isalnum(ch);
  }

  ConnectTheDots(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  vector<string> board;
  const string turn = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
};