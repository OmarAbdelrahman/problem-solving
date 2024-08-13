#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

class LastBlood {
public:
  void solve() {
    int problems, teams, submissions;
    in >> problems >> teams >> submissions;
    std::vector<std::vector<std::pair<int, int>>> p(problems);
    while (submissions-- != 0) {
      int time, id;
      std::string problem, verdict;
      in >> time >> id >> problem >> verdict;
      if (verdict[0] == 'Y') {
        const int at = problem[0] - 'A';
        bool found = false;
        for (const auto& submission : p[at]) {
          if (submission.second == id) {
            found = true;
          }
        }
        if (!found) {
          p[at].emplace_back(time, id);
        }
      }
    }
    for (int i = 0; i < problems; i++) {
      out << char(i + 'A') << ' ';
      if (p[i].empty()) {
        out << "- -" << '\n';
      } else {
        out << p[i].back().first << ' ' << p[i].back().second << '\n';
      }
    }
  }

  LastBlood(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};