#include <bits/stdc++.h>

using namespace std;

struct node {
  int b, e, m, sm, bg, x;

  node() : x(0) {}

  node(int _sm, int _bg) : sm(_sm), bg(_bg) {}

  void combine(const node &other) {
    sm = min(sm, other.sm);
    bg = max(bg, other.bg);
  }

  void update(int v) {
    x += v;
    sm += v;
    bg += v;
  }
};

struct segment_tree {

  explicit segment_tree(const vector<int> &_a) : a(_a) {
    t = vector<node>((int) a.size() * 4);
    build();
  }

  void build() {
    build(0, 0, (int) a.size() - 1);
  }

  void update(int b, int e, int x) {
    update(0, b, e, x);
  }

  node query(int b, int e) {
    return query(0, b, e);
  }

private:
  int L(int i) const {
    return 2 * i + 1;
  }

  int R(int i) const {
    return 2 * i + 2;
  }

  void collect(int i) {
    t[i].sm = min(t[L(i)].sm, t[R(i)].sm);
    t[i].bg = max(t[L(i)].bg, t[R(i)].bg);
  }

  void put_initial_value(int i, int ai) {
    t[i].sm = t[i].bg = a[ai];
  }

  void push(int i) {
    t[L(i)].update(t[i].x);
    t[R(i)].update(t[i].x);
    // reset after pushing
    t[i].x = 0;
  }

  void build(int i, int b, int e) {
    node &n = t[i];
    n.b = b;
    n.e = e;
    n.m = (b + e) / 2;
    if (n.b == n.e) {
      put_initial_value(i, b);
    } else {
      build(L(i), n.b, n.m);
      build(R(i), n.m + 1, n.e);
      collect(i);
    }
  }

  void update(int i, int b, int e, int x) {
    node &n = t[i];
    if (b == n.b && e == n.e) {
      n.update(x);
    } else {
      push(i);
      if (b <= n.m)
        update(L(i), b, min(n.m, e), x);
      if (e > n.m)
        update(R(i), max(b, n.m + 1), e, x);
      collect(i);
    }
  }

  node query(int i, int b, int e) {
    node &n = t[i];
    if (n.b == b && n.e == e) {
      return n;
    } else {
      push(i);
      node result(numeric_limits<int>::max(), numeric_limits<int>::min());
      if (b <= n.m)
        result.combine(query(L(i), b, min(n.m, e)));
      if (e > n.m)
        result.combine(query(R(i), max(b, n.m + 1), e));
      return result;
    }
  }

  vector<node> t;
  vector<int> a;
};

class CMediumDesign {
public:
  void solveOne(istream &is, ostream &os) {
    int n, m;
    is >> n >> m;

    vector<int> v(m, 0);
    segment_tree tree(v);

    int b = 0;
    for (int i = 0; i < n; i++) {
      int l, r;
      is >> l >> r;
      tree.update(l - 1, r - 1, 1);
    }

    os << tree.query(0, m - 1).bg - tree.query(0, m - 1).sm << '\n';
  }

  void solve(istream &is, ostream &os) {
    int t;
    is >> t;
    for (int i = 0; i < t; i++) {
      solveOne(is, os);
    }
  }
};