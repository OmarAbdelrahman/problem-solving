#include <bits/stdc++.h>
#include "../../../library/vector_io.hpp"

using namespace std;

class CAnjisBinaryTree {
public:
  void solveOne() {
    int n;
    in >> n;
    string s;
    in >> s;
    vector<array<int, 2>> tree(n);
    in >> tree;
    for (auto& nodes : tree) {
      for (int& node : nodes) {
        node--;
      }
    }
    vector<int> dp(n, -1);
    function<int(const int&)> dfs = [&](const int& vertex) -> int {
      const int& L = tree[vertex][0];
      const int& R = tree[vertex][1];
      if (L == -1 && R == -1) {
        return dp[vertex] = 0;
      }
      if (dp[vertex] != -1) {
        return dp[vertex];
      }
      dp[vertex] = numeric_limits<int>::max();
      if (L != -1) {
        dp[vertex] = min(dp[vertex], dfs(L) + (s[vertex] != 'L'));
      }
      if (R != -1) {
        dp[vertex] = min(dp[vertex], dfs(R) + (s[vertex] != 'R'));
      }
      return dp[vertex];
    };
    out << dfs(0) << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  CAnjisBinaryTree(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};