#include <iomanip>
#include <iostream>

class ClockHands {
public:
  // angle per minute = 360 / 60 = 6 degrees
  // angle between 'minute-hand' and 12 o'clock = 6 * minutes
  // angle per hour = 360 / 12 = 30 degrees
  // angle between 'hour-hand' and 12 o'clock = 30 * hours + 0.5 * minutes
  // angle between 'minute-hand' and 'hour-hand' = |angle-hours - angle-minutes|
  // angle between 'hour-hand' and 'minute-hand' = |30 * hours + 0.5 * minutes - 6 * minutes|
  // angle between 'hour-hand' and 'minute-hand' = |30 * hours - 5.5 * minutes|

  void solveOne(int h, int m) {
    double angle = 30.0 * h - 5.5 * m;
    if (angle < 0) angle = -angle;
    if (angle > 180) angle = 360 - angle;
    out << std::fixed << std::setprecision(3) << angle << '\n'; 
  }

  void solve() {
    char dot;
    for (int h, m; in >> h >> dot >> m && (h || m); ) {
      solveOne(h, m);
    }
  }

  ClockHands(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};
