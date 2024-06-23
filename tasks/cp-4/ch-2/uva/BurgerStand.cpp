#include <iostream>
#include <string>

class BurgerStand {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      std::string road;
      in >> road;
      auto is_driveway = [](const char ch) { return ch == 'D'; };
      auto is_bus_stop = [](const char ch) { return ch == 'B'; };
      auto is_side_street = [](const char ch) { return ch == 'S'; };
      int n = road.size();
      int count = 0;
      for (int i = 0; i < n; i++) {
        const char front = road[i];
        if (is_driveway(front) || is_bus_stop(front) || is_side_street(front)) {
          continue;
        }
        if (i < n - 1) {
          const char five_front = road[i + 1];
          if (is_bus_stop(five_front) || is_side_street(five_front)) {
            continue;
          }
        }
        if (i < n - 2) {
          const char ten_front = road[i + 2];
          if (is_bus_stop(ten_front)) {
            continue;
          }
        }
        if (i > 0) {
          const char five_back = road[i - 1];
          if (is_side_street(five_back)) {
            continue;
          }
        }
        count += 1;
      }
      out << "Case " << _ << ": " << count << '\n';
    }
  }

  BurgerStand(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};