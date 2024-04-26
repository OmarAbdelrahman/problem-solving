#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <cmath>

class KeyboardComparison {
public:
  void solveOne(const std::string& line) {
    double two_hands_qwerty = 0;
    double one_hand_qwerty = 0;
    double one_hand_dvorak = 0;
    for (char ch : line) {
      two_hands_qwerty += two_hands_qwerty_dist[ch];
      one_hand_qwerty += one_hand_qwerty_dist[ch];
      one_hand_dvorak += dvorak_dist[ch];
    }
    out << std::fixed << std::setprecision(2) << two_hands_qwerty << ' ' << one_hand_qwerty << ' ' << one_hand_dvorak << '\n';
  }

  void solve() {
    for (std::string line; std::getline(in, line); )
      solveOne(line);
  }

  KeyboardComparison(std::istream& in, std::ostream& out)
    : in(in), out(out)
  {
    build_pos(qwerty, qwerty_pos);
    build_pos(QWERTY, qwerty_pos);
    build_pos(dvorak, dvorak_pos);
    build_pos(DVORAK, dvorak_pos);
    build_dist(two_hands_qwerty_home, qwerty_pos, two_hands_qwerty_dist);
    build_dist(one_hand_qwerty_home, qwerty_pos, one_hand_qwerty_dist);
    build_dist(dvorak_home, dvorak_pos, dvorak_dist);
  }

private:
  double get_distance(const int x1, const int y1, const int x2, const int y2) {
    return 2.0 * std::hypot(double(x1 - x2), double(y1 - y2));
  }

  void build_dist(const std::string& home, const std::unordered_map<char, std::tuple<int, int>>& pos, std::unordered_map<char, double>& dist) {
    for (const char& start_ch : home) {
      int xh, yh;
      std::tie(xh, yh) = pos.at(start_ch);
      for (const auto& kv : pos) {
        const char ch = kv.first;
        int x, y;
        std::tie(x, y) = kv.second;
        if (dist.find(ch) == dist.end()) {
          dist[ch] = get_distance(xh, yh, x, y);
        } else {
          dist[ch] = std::min(dist[ch], get_distance(xh, yh, x, y));
        }
      }
    }
  }

  void build_pos(const std::vector<std::string>& layout, std::unordered_map<char, std::tuple<int, int>>& pos) {
    for (int i = layout.size() - 1; i >= 0; i--) {
      for (int j = 0; j < layout[i].size(); j++) {
        const char ch = layout[i][j];
        if (ch == ' ') continue;
        pos[ch] = std::make_tuple(layout.size() - i - 1, j);
      }
    }
  }

  std::istream& in;
  std::ostream& out;

  std::unordered_map<char, double> two_hands_qwerty_dist;
  std::unordered_map<char, double> one_hand_qwerty_dist;
  std::unordered_map<char, double> dvorak_dist;

  std::unordered_map<char, std::tuple<int, int>> qwerty_pos;
  std::unordered_map<char, std::tuple<int, int>> dvorak_pos;

  const std::string two_hands_qwerty_home = "asdfjkl;";
  const std::string one_hand_qwerty_home = "fghj";
  const std::string dvorak_home = "ehtd";

  const std::vector<std::string> qwerty = {
    "`1234567890-=",
    " qwertyuiop[]\\",
    " asdfghjkl;'",
    " zxcvbnm,./"
  };

  const std::vector<std::string> QWERTY = {
    "~!@#$%^&*()_+",
    " QWERTYUIOP{}|",
    " ASDFGHJKL:\"",
    " ZXCVBNM<>?"
  };

  const std::vector<std::string> dvorak = {
    "`123qjlmfp/[]",
    " 456.orsuyb;=\\",
    " 789aehtdck-",
    " 0zx,inwvg'"
  };

  const std::vector<std::string> DVORAK = {
    "~!@#QJLMFP?{}",
    " $%^>ORSUYB:+|",
    " &*(AEHTDCK_",
    " )ZX<INWVG\""
  };
};
