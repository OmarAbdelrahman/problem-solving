#include <bits/stdc++.h>
using namespace std;

class BenderBRodrguezProblem {
public:
  struct vector_t {
    int x, y, z;

    vector_t() = default;

    vector_t(int _x, int _y, int _z)
      : x(_x), y(_y), z(_z) { }

    explicit vector_t(const string& d): x(), y(), z() {
      int sgn = d[0] == '-' ? -1 : +1;
      if (d[1] == 'y') y = sgn;
      if (d[1] == 'z') z = sgn;
    }

    inline static vector_t unit_x() {
      return {1, 0, 0};
    }

    inline static vector_t unit_y() {
      return {0, 1, 0};
    }

    inline static vector_t unit_z() {
      return {0, 0, 1};
    }

    inline bool is_null() const {
      return !x && !y && !z;
    }

    vector_t operator * (const vector_t& other) const {
      return {y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x};
    }

    friend ostream& operator << (ostream& o, const vector_t& v) {
      if (v.x) {
        o << (v.x < 0 ? "-x" : "+x");
      } else if (v.y) {
        o << (v.y < 0 ? "-y" : "+y");
      } else {
        o << (v.z < 0 ? "-z" : "+z");
      }
      return o;
    }
  };

  void solve() {
    for (int n; in >> n && n; ) {
      vector_t r = vector_t::unit_x();
      while (--n) {
        string s;
        in >> s;
        if (s[0] == 'N') {
          continue;
        }
        auto a = vector_t(s);
        vector_t b = vector_t::unit_x() * a;
        vector_t c = b * r;
        if (c.is_null()) {
          continue;
        }
        r = c;
      }
      out << r << '\n';
    }
  }

  BenderBRodrguezProblem(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};