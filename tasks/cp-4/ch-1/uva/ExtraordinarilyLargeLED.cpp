#include <iostream>
#include <string>
#include <vector>
#include <array>

class ExtraordinarilyLargeLED {
public:
  struct time_t {
    int h, m, s;

    time_t(): h(0), m(0), s(0) { }

    bool operator < (const time_t& other) const {
      if (h != other.h) return h < other.h;
      if (m != other.m) return m < other.m;
      return s < other.s;
    }

    inline int seconds() const {
      return h * 3600 + m * 60 + s;
    }

    bool operator == (const time_t& other) const {
      return h == other.h && m == other.m && s == other.s;
    }

    friend std::istream& operator >> (std::istream& i, time_t& t) {
      char colon;
      i >> t.h >> colon >> t.m >> colon >> t.s;
      return i;
    }

    friend std::ostream& operator << (std::ostream& o, const time_t& t) {
      return o << t.h << ':' << t.m << ':' << t.s;
    }
  };

  void solveOne(const int C) {
    const int n = int(times.size());
    int64_t result = 0;
    for (int i = 0; i + 1 < n; i++) {
      const int64_t diff = times[i + 1].seconds() - times[i].seconds();
      result += diff * (cost(scores[i][0]) + cost(scores[i][1]));
    }
    out << "Case " << C << ": " << result << '\n';
  }

  void solve() {
    int C = 1;
    for (std::string cmd, team; in >> cmd; C++) {
      if (cmd == "START") {
        time_t t;
        in >> t;
        score_sums.fill(0);
        times = std::vector<time_t>();
        teams = std::vector<std::string>();
        scores = std::vector<std::array<int, 2>>();
        insert(t, "", 0);
        for (int score; in >> cmd && cmd != "END"; ) {
          in >> t >> team >> score;
          insert(t, team, score);
        }
        in >> t;
        insert(t, "", 0);
        solveOne(C);
      }
    }
  }

  ExtraordinarilyLargeLED(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  void insert(const time_t& t, const std::string& team, const int score) {
    times.emplace_back(t);
    teams.emplace_back(team);
    if (score) {
      score_sums[team == "guest"] += score;
    }
    scores.emplace_back(score_sums);
  }

  int cost(int n) {
    if (n == 0) return led[0];
    int c = 0;
    while (n > 0) {
      c += led[n % 10];
      n /= 10;
    }
    return c;
  }

  std::istream& in;
  std::ostream& out;

  std::vector<time_t> times;
  std::vector<std::string> teams;
  std::vector<std::array<int, 2>> scores;
  std::array<int, 2> score_sums;

  const std::array<int, 10> led = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
};
