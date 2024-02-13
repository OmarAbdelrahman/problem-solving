#include <bits/stdc++.h>
#include "../../../library/vector_io.hpp"
using namespace std;

class GBicycles {
public:
  struct state_t {
    int v;
    int64_t slow, cost;

    state_t(const int _v, const int64_t _c)
      : v(_v), slow(), cost(_c) { }

    state_t(const int _v, const int64_t _s, const int64_t _c)
      : v(_v), slow(_s), cost(_c) { }

    bool operator < (const state_t& s) const {
      return cost > s.cost;
    }
  };

  void solveOne() {
    int n, m;
    in >> n >> m;
    vector<vector<state_t>> nodes(n);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      in >> a >> b >> c;
      nodes[a - 1].emplace_back(b - 1, c);
      nodes[b - 1].emplace_back(a - 1, c);
    }
    vector<int64_t> slow(n);
    in >> slow;
    auto solve = [&](const int trg) -> int64_t {
      vector<vector<bool>> visited(n, vector<bool>(S, false));
      vector<vector<int64_t>> dist(n, vector<int64_t>(S, INF));
      priority_queue<state_t> q;
      dist[0][slow[0]] = 0;
      for (q.emplace(0, slow[0], 0); !q.empty(); ) {
        const state_t node = q.top();
        q.pop();
        if (visited[node.v][node.slow]) continue;
        visited[node.v][node.slow] = true;
        for (const state_t& u : nodes[node.v]) {
          int64_t best_slow = min(node.slow, slow[u.v]);
          if (node.cost + u.cost * node.slow < dist[u.v][best_slow]) {
            dist[u.v][best_slow] = node.cost + u.cost * node.slow;
            q.emplace(u.v, best_slow, dist[u.v][best_slow]);
          }
        }
      }
      return ranges::min(dist[trg]);
    };
    out << solve(n - 1) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  GBicycles(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int64_t INF = numeric_limits<int64_t>::max() / 2;
  const int S = 1001;
};