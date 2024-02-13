#include <bits/stdc++.h>
#include "../library/vector_io.hpp"
using namespace std;

class FGreetings {
public:
  struct state_t {
    int t, c;

    bool operator < (const state_t& s) const {
      return c > s.c;
    }
  };

  void solveOne() {
    int n, m;
    in >> n >> m;
    vector<vector<state_t>> nodes(n);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      in >> a >> b >> c;
      nodes[a - 1].push_back({b - 1, c});
      nodes[b - 1].push_back({a - 1, c});
    }
    vector<int> s(n);
    in >> s;
    auto solve = [&](const int src, const int trg) -> int {
      vector<bool> visited(n, false);
      vector<int> dist(n, numeric_limits<int>::max() / 2);
      dist[src] = 0;
      priority_queue<state_t> q;
      q.push({src, 0});
      while (!q.empty()) {
        int i = q.top().t;
        int c = q.top().c;
        q.pop();
        if (visited[i]) continue;
        visited[i] = true;
        if (src == trg) return dist[trg];
        for (int j = 0; j < ssize(nodes[i]); j++) {
          int n_c = c + (nodes[i][j].c * s[j]);
          if (n_c < dist[nodes[i][j].t]) {
            dist[nodes[i][j].t] = n_c;
            q.push({nodes[i][j].t, n_c});
          }
        }
      }
      return dist[trg];
    };
    out << solve(0, n) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  FGreetings(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};