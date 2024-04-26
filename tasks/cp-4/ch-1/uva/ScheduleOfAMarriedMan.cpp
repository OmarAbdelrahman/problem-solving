#include "iostream"

class ScheduleOfAMarriedMan {
public:
  struct time_t {
    int h, m;

    time_t(): h(0), m(0) { }

    bool operator < (const time_t& other) const {
      if (h != other.h) return h < other.h;
      return m < other.m;
    }

    bool operator == (const time_t& other) const {
      return h == other.h && m == other.m;
    }

    friend std::istream& operator >> (std::istream& i, time_t& t) {
      char colon;
      i >> t.h >> colon >> t.m;
      return i;
    }
  };

  struct event_t {
    time_t begin, end;

    bool overlaps(const event_t& other) const {
      return begin < other.end && other.begin < end || (begin == other.end || other.begin == end);
    }
  };

  void solveOne(const int it) {
    event_t wife, meeting;
    in >> wife.begin >> wife.end;
    in >> meeting.begin >> meeting.end;
    out << "Case " << it << ": ";
    if (wife.overlaps(meeting)) {
      out << "Mrs Meeting\n";
    } else {
      out << "Hits Meeting\n";
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      solveOne(_);
    }
  }

  ScheduleOfAMarriedMan(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};
