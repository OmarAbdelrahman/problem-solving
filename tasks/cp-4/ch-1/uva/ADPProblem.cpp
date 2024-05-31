#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <cmath>

#include "../../../../library/char_utils.hpp"

class ADPProblem {
public:
  struct expression_t {
    int x = 0;
    int value = 0;

    bool operator == (const expression_t& other) const {
      return x == other.x && value == other.value;
    }

    int solve(expression_t rhs) {
      if (*this == rhs) throw std::runtime_error("IDENTITY");
      if (x == rhs.x && value != rhs.value) throw std::runtime_error("IMPOSSIBLE");
      x += -rhs.x;
      rhs.value += -value;
      return (int) std::floor(rhs.value * 1.0 / x * 1.0);
    }
  };

  void solveOne(const std::string& equation) {
    std::string lhs, rhs;
    std::size_t at = equation.find('=');
    for (std::size_t i = 0; i < at; i++)
      lhs += equation[i];
    for (std::size_t i = at + 1; i < equation.size(); i++)
      rhs += equation[i];

    lhs = space_it(lhs);
    rhs = space_it(rhs);

    expression_t l = simplify(lhs);
    expression_t r = simplify(rhs);

    try {
      out << l.solve(r) << '\n';
    } catch (const std::runtime_error& e) {
      out << e.what() << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    while (nt--) {
      std::string equation;
      in >> equation;
      solveOne(equation);
    }
  }

  ADPProblem(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  expression_t simplify(const std::string& exp) {
    std::stringstream sin(exp);
    std::vector<std::string> parts;
    for (std::string part; sin >> part; parts.emplace_back(part));

    auto decode = [](const std::string& x, const int sign = 1) {
      if (x.size() == 1) return sign;
      return sign * std::stoi(x.substr(0, x.size() - 1));
    };

    expression_t r;
    if (std::string front = parts[0]; front.back() == 'x') {
      r.x += decode(front);
    } else {
      r.value += std::stoi(front);
    }
    for (int i = 1; i < parts.size(); i++) {
      const std::string part = parts[i];
      if (is_digit(part[0]) || part == "x") {
        const int sign = parts[i - 1] == "-" ? -1 : 1;
        if (part.back() == 'x') {
          r.x += decode(part, sign);
        } else {
          r.value += sign * std::stoi(part);
        }
      }
    }
    return r;
  }

  std::string space_it(const std::string& str) {
    std::string r;
    for (const char ch : str) {
      if (ch == '+' || ch == '-') {
        r += ' ';
        r += ch;
        r += ' ';
      } else {
        r += ch;
      }
    }
    return r;
  }

private:
  std::istream& in;
  std::ostream& out;
};