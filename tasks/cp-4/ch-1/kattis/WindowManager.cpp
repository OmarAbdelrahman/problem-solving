#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdio>

class WindowManager {
public:
  void open(int case_i, int n, int m) {
    int x, y, w, h;
    in >> x >> y >> w >> h;
    bool fit = x + w <= n && y + h <= m;
    for (int i = 0; i < x0.size(); i++) {
      if (overlap(x0[i], xn[i], x, x + w - 1) && overlap(y0[i], yn[i], y, y + h - 1))
        fit = false;
    }
    if (fit) {
      x0.emplace_back(x);
      xn.emplace_back(x + w - 1);
      y0.emplace_back(y);
      yn.emplace_back(y + h - 1);
    } else {
      does_not_fit(case_i, command);
    }
  }

  void close(int case_i, int n, int m) {
    int x, y;
    in >> x >> y;
    bool found = false;
    for (int i = 0; i < x0.size(); i++) {
      if (x >= x0[i] && x <= xn[i] && y >= y0[i] && y <= yn[i]) {
        found = true;
        x0.erase(x0.begin() + i);
        xn.erase(xn.begin() + i);
        y0.erase(y0.begin() + i);
        yn.erase(yn.begin() + i);
        break;
      }
    }
    if (!found) {
      no_window(case_i, command);
    }
  }

  void resize(int case_i, int n, int m) {
    int x, y, w, h;
    in >> x >> y >> w >> h;
    int at = -1;
    for (int i = 0; i < x0.size() && at == -1; i++) {
      if (x >= x0[i] && x <= xn[i] && y >= y0[i] && y <= yn[i]) {
        at = i;
      }
    }
    if (at == -1) {
      no_window(case_i, command);
      return;
    }
    bool fit = x0[at] + w <= n && y0[at] + h <= m;
    for (int i = 0; i < x0.size(); i++) {
      if (i == at) continue;
      if (overlap(x0[i], xn[i], x0[at], x0[at] + w - 1) && overlap(y0[i], yn[i], y0[at], y0[at] + h - 1))
        fit = false;
    }
    if (fit) {
      xn[at] = x0[at] + w - 1;
      yn[at] = y0[at] + h - 1;
    } else {
      does_not_fit(case_i, command);
    }
  }

  void move(int case_i, int n, int m) {
    int x, y, dx, dy;
    in >> x >> y >> dx >> dy;
    int at = -1;
    for (int i = 0; i < x0.size() && at == -1; i++) {
      if (x >= x0[i] && x <= xn[i] && y >= y0[i] && y <= yn[i]) {
        at = i;
      }
    }
    if (at == -1) {
      no_window(case_i, command);
      return;
    }
    bool only_x = dx != 0;
    bool flip = dx < 0 || dy < 0;
    if (!only_x) {
      std::swap(n, m);
      swap();
      std::swap(dx, dy);
    }
    if (flip) {
      for (int i = 0; i < x0.size(); i++) {
        std::swap(x0[i], xn[i]);
        x0[i] = n - 1 - x0[i];
        xn[i] = n - 1 - xn[i];
      }
      dx = -dx;
    }
    int start_x = dx;
    std::vector<bool> used(x0.size(), false);
    used[at] = true;
    while (dx > 0) {
      int dist = dx;
      int where = -1;
      // distance to wall
      for (int i = 0; i < x0.size(); i++) {
        if (!used[i]) continue;
        dist = std::min(dist, n - xn[i] - 1);
      }
      if (dist == 0) {
        break;
      }
      for (int src = 0; src < x0.size(); src++) {
        if (!used[src]) continue;
        for (int trg = 0; trg < x0.size(); trg++) {
          if (used[trg]) continue;
          if (overlap(y0[src], yn[src], y0[trg], yn[trg]) && x0[trg] > xn[src] && x0[trg] - xn[src] <= dist) {
            dist = x0[trg] - xn[src] - 1;
            where = trg;
          }
        }
      }
      for (int i = 0; i < x0.size(); i++) {
        if (!used[i]) continue;
        x0[i] += dist;
        xn[i] += dist;
      }
      dx -= dist;
      if (where != -1) {
        used[where] = true;
      }
    }
    if (dx != 0) {
      moved_x_instead(case_i, start_x, start_x - dx);
    }
    if (flip) {
      for (int i = 0; i < x0.size(); i++) {
        std::swap(x0[i], xn[i]);
        x0[i] = n - 1 - x0[i];
        xn[i] = n - 1 - xn[i];
      }
    }
    if (!only_x) {
      std::swap(n, m);
      swap();
    }
  }

  void solve() {
    int n, m;
    in >> n >> m;
    clear();
    for (int _ = 1; in >> command; _++) {
      const char cmd = command[0];
      if (cmd == 'O') open(_, n, m);
      else if (cmd == 'C') close(_, n, m);
      else if (cmd == 'R') resize(_, n, m);
      else move(_, n, m);
    }
    out << x0.size() << " window(s):" << '\n';
    for (int i = 0; i < x0.size(); i++) {
      out << x0[i] << ' ' << y0[i] << ' ' << xn[i] - x0[i] + 1 << ' ' << yn[i] - y0[i] + 1 << '\n';
    }
  }

  WindowManager(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  inline bool overlap(int start_x, int end_x, int st_x, int e_x) const {
    return std::max(start_x, st_x) <= std::min(end_x, e_x);
  }

  inline void does_not_fit(int case_i, const std::string& command) const {
    out << "Command " << case_i << ": " << command << " - window does not fit" << '\n';
  }

  inline void no_window(int case_i, const std::string& command) const {
    out << "Command " << case_i << ": " << command << " - no window at given position" << '\n';
  }

  inline void moved_x_instead(int case_i, int desired, int actual) const {
    out << "Command " << case_i << ": MOVE - moved " << actual << " instead of " << desired << '\n';
  }

  void clear() {
    x0.clear();
    xn.clear();
    y0.clear();
    yn.clear();
  }

  void swap() {
    x0.swap(y0);
    xn.swap(yn);
  }

private:
  std::istream& in;
  std::ostream& out;

  std::string command;
  std::vector<int> x0, xn;
  std::vector<int> y0, yn;
};