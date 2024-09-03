#include <iostream>
#include <vector>
#include <algorithm>

#include "../../../../library/vector_utils.hpp"

/*
 * Beefy problem statement, it goes down to understand the sorting criteria.
 *   Hint: Downward acceleration only depends on the 'Height', since the gravity is the same for all ants.
 */
class FallingAnts {
public:
  struct ant {
    int l, w, h;

    inline int volume() const { return l * w * h; }

    inline bool operator<(const ant& other) const {
      if (h != other.h) return h > other.h;
      return volume() > other.volume();
    }

    inline friend std::istream& operator>>(std::istream& i, ant& a) { return i >> a.l >> a.w >> a.h; }
    inline friend std::ostream& operator<<(std::ostream& o, const ant& a) { return o << a.volume(); }
  };

  void solve() {
    for (int n; in >> n && n != 0; ) {
      std::vector<ant> v(n);
      in >> v;
      std::sort(v.begin(), v.end());
      out << v.front() << '\n';
    }
  }

  FallingAnts(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};