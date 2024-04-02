#include "iostream"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "array"

class ConsanguineCalculations {
public:
  void print(const std::unordered_set<std::string>& maybe_types, char default_, char may_be, bool both) {
    if (maybe_types.size() == 1 && !both) {
      out << *maybe_types.begin() << default_;
      return;
    }
    auto it = maybe_types.begin();
    out << '{';
    out << *it << default_;
    if (both) {
      out << ", " << *it << may_be;
    }
    for (it++; it != maybe_types.end(); it++) {
      out << ", " << *it << default_;
      if (both) {
        out << ", " << *it << may_be;
      }
    }
    out << '}';
  }

  void son() {
    std::unordered_set<std::string> maybe_types;
    const std::string p1_comb = combination[p1];
    const std::string p2_comb = combination[p2];
    for (const char p1_ : p1_comb) {
      for (const char p2_ : p2_comb) {
        const std::string type = abo_type[p1_ + std::string(1, p2_)];
        maybe_types.insert(type);
      }
    }
    print(maybe_types, '-', '+', p1.back() == '+' || p2.back() == '+');
  }

  void parent(const std::string& p) {
    const std::string son_abo = s.substr(0, s.size() - 1);
    std::unordered_set<std::string> maybe_types;
    for (const std::string& comp : comps) {
      for (const char p_ : combination[p]) {
        for (const char c_ : comp) {
          const std::string type = abo_type[p_ + std::string(1, c_)];
          if (type == son_abo) {
            maybe_types.insert(abo_type[comp]);
          }
        }
      }
    }
    if (maybe_types.empty()) {
      out << "IMPOSSIBLE";
    } else {
      print(maybe_types, '+', '-', !(p.back() == '-' && s.back() == '+'));
    }
  }

  void solveOne() {
    if (p1 == "?") {
      parent(p2);
      out << ' ' << p2 << ' ' << s;
    } else if (p2 == "?") {
      out << p1 << ' ';
      parent(p1);
      out << ' ' << s;
    } else {
      out << p1 << ' ' << p2 << ' ';
      son();
    }
    out << '\n';
  }

  void solve() {
    for (int _ = 1; in >> p1 >> p2 >> s && p1[0] != 'E'; _++) {
      out << "Case " << _ << ": ";
      solveOne();
    }
  }

  ConsanguineCalculations(std::istream& in, std::ostream& out): in(in), out(out) {
    for (int i = 0; i < COMPS; i++) {
      abo_type[comps[i]] = abo[i];
    }
    abo_type["BA"] = "AB";
    abo_type["OA"] = "A";
    abo_type["OB"] = "B";

    combination["A+"] = "AO";
    combination["A-"] = combination["A+"];
    combination["B+"] = "BO";
    combination["B-"] = combination["B+"];
    combination["AB+"] = "AB";
    combination["AB-"] = combination["AB+"];
    combination["O+"] = "OO";
    combination["O-"] = combination["O+"];
  }

private:
  std::istream& in;
  std::ostream& out;

  static const int COMPS = 6;

  const std::array<std::string, COMPS> comps{"AA", "AB", "AO", "BB", "BO", "OO"};
  const std::array<std::string, COMPS> abo{"A", "AB", "A", "B", "B", "O"};

  std::unordered_map<std::string, std::string> abo_type;
  std::unordered_map<std::string, std::string> combination;
  std::string p1, p2, s;
};
