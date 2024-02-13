#include <bits/stdc++.h>

using namespace std;

struct segment_t {
  int l, r;

  inline bool contains(const segment_t& segment) const {
    if (segment.l > r || segment.r < l) return false;
    return true;
  }

  inline void extend(const int k) {
    l -= k;
    r += k;
  }

  inline void update(const segment_t& segment) {
    l = max(l, segment.l);
    r = min(r, segment.r);
  }
};

class DJumpingThroughSegments {
public:
  void solveOne() {
    int n;
    in >> n;
    vector<segment_t> segments(n);
    for (auto& it : segments) {
      in >> it.l >> it.r;
    }
    auto can = [&](const int k) -> bool {
      segment_t range = {0, 0};
      for (const segment_t& segment : segments) {
        range.extend(k);
        if (!range.contains(segment)) {
          return false;
        }
        range.update(segment);
      }
      return true;
    };
    int result = *ranges::partition_point(ranges::iota_view(0, int(10e9)), [&](const int& k) { return !can(k); });
    out << result << '\n';
  }


  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  DJumpingThroughSegments(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};