#include <iostream>
#include <algorithm>
#include <array>

class OnlyIDidIt {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      size.fill(0);
      for (int i = 0; i < FRIENDS; i++) {
        solved[i].fill(false);
        uniquely_solved[i].fill(false);
      }
      for (int i = 0; i < FRIENDS; i++) {
        int n;
        in >> n;
        while (n-- != 0) {
          int problem;
          in >> problem;
          solved[i][problem] = true;
        }
      }
      for (int problem = 0; problem < S; problem++) {
        for (int i = 0; i < FRIENDS; i++) {
          const int j = (i + 1) % FRIENDS;
          const int k = (i + 2) % FRIENDS;
          if (solved[i][problem] && !solved[j][problem] && !solved[k][problem]) {
            uniquely_solved[i][problem] = true;
            size[i] += 1;
          }
        }
      }
      std::size_t which = *std::max_element(size.begin(), size.end());
      out << "Case #" << _ << ':' << '\n';
      for (int i = 0; i < FRIENDS; i++) {
        if (size[i] == which) {
          out << i + 1 << ' ' << size[i];
          for (int problem = 0; problem < S; problem++) {
            if (uniquely_solved[i][problem]) {
              out << ' ' << problem;
            }
          }
          out << '\n';
        }
      }
    }
  }

  OnlyIDidIt(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  static const int FRIENDS = 3;
  static const int S = 10000 + 1;

  std::array<std::array<bool, S>, FRIENDS> solved;
  std::array<std::size_t, FRIENDS> size;
  std::array<std::array<bool, S>, FRIENDS> uniquely_solved;
};