#include <iostream>
#include <string>
#include <array>
#include <tuple>

#include "../../../../library/adhoc_utils.hpp"
#include "../../../../library/array_io.hpp"

class RobotMaps {
public:
  void solve() {
    for (int n, m; in >> n >> m && (n || m); ) {
      if (n == 0 && m == 0) break;

      int ni, mi;
      in >> ni >> mi;
      ni -= 1;
      mi -= 1;

      for (int i = 0; i < n; i++)
        board[i].resize(m);

      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
          in >> board[i][j];
          taken[i][j] = false;
        }

      std::array<std::string, N> initial_board = board;
      board.fill(std::string(m, '?'));

      board[ni][mi] = initial_board[ni][mi];
      taken[ni][mi] = true;
      int cnt = 0;
      while (true) {
        int ns = -1, ms = -1;
        for (const auto& d : _dir_4) {
          int x, y;
          std::tie(x, y) = d;
          const int nn = ni + x;
          const int nm = mi + y;
          if (nn >= 0 && nm >= 0 && nn < n && nm < m && !taken[nn][nm]) {
            board[nn][nm] = initial_board[nn][nm];
            if (board[nn][nm] == O && ns == -1) {
              taken[nn][nm] = true;
              ns = nn;
              ms = nm;
            }
          }
        }
        if (ns == -1) break;
        ni = ns;
        mi = ms;
        cnt += 1;
      }

      out << '\n';
      print_board(n, m);
      out << '\n';
      out << "NUMBER OF MOVEMENTS: " << cnt << '\n';
    }
  }

  RobotMaps(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  inline void print_horizontal_line(const int n) {
    out << V;
    for (int i = 0; i < n; i++) out << H << H << H << V;
    out << '\n';
  }

  inline void print_row(const int at, const int m) {
    out << V;
    for (int i = 0; i < m; i++)
      out << ' ' << board[at][i] << ' ' << V;
    out << '\n';
  }

  inline void print_board(const int n, const int m) {
    print_horizontal_line(m);
    for (int i = 0; i < n; i++) {
      print_row(i, m);
      print_horizontal_line(m);
    }
  }

private:
  std::istream& in;
  std::ostream& out;

  static const int N = 11;

  std::array<std::string, N> board;
  bool taken[N][N];

  const char V = '|';
  const char H = '-';
  const char O = '0';
};