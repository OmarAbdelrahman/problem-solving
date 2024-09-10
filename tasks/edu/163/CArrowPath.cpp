#include <bits/stdc++.h>

#include "../../../library/io.hpp"

using namespace std;
using namespace io;

class CArrowPath {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<string> b(2);
    in >> b;
    vector<vector<bool>> taken(2, vector<bool>(n, false));
    queue<pair<int, int>> q;
    auto ok = [&](const int x, const int y) {
      return x >= 0 && x < 2 && y >= 0 && y < n;
    };
    auto push = [&](const int x, const int y) {
      if (!ok(x, y)) return;
      if (taken[x][y]) return;
      taken[x][y] = true;
      q.emplace(x, y);
    };
    for (push(0, 0); !q.empty(); q.pop()) {
      auto [x, y] = q.front();
      for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++)
          if ((dx == 0) ^ (dy == 0)) {
            int nx = x + dx;
            int ny = y + dy;
            if (ok(nx, ny)) {
              if (b[nx][ny] == L) ny -= 1; else ny += 1;
              push(nx, ny);
            }
          }
    }
    print_yes_or_no(out, taken[1][n - 1]);
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne();
    }
  }

  void print_yes_or_no(std::ostream& o, const bool& condition, const bool new_line = true) {
    o << (condition ? "YES" : "NO") << (new_line ? '\n' : char());
  }
  std::string yes_or_no(const bool condition) {
    return condition ? "YES" : "NO";
  }
  template<typename T = std::string>
  T value_conditional(const bool condition, const std::array<T, 2>& options) {
    return options[condition];
  }
  template<typename T = std::string>
  void print_conditional(std::ostream& o, const bool condition, const std::array<T, 2>& options, const bool new_line = true) {
    o << options[condition] << (new_line ? '\n' : char());
  }
  template<typename T>
  void print_case(std::ostream& o, const int case_i, const T& result, const bool new_line = true) {
    o << "Case " << case_i << ": " << result << (new_line ? '\n' : char());
  }

  CArrowPath(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const char R = '>';
  const char L = '<';
};