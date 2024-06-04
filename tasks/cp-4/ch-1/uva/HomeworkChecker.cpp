#include <iostream>
#include <string>

class HomeworkChecker {
public:
  inline int solveOne(const int a, const char op, const int b, const int c) {
    return op == '+' ? a + b == c : a - b == c;
  }

  void solve() {
    int result = 0, a, b;
    char op, eq;
    std::string rhs;
    while (in >> a >> op >> b >> eq >> rhs) {
      if (rhs.back() == '?') continue;
      result += solveOne(a, op, b, std::stoi(rhs));
    }
    out << result << '\n';
  }

  HomeworkChecker(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};