#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cassert>

#include "../../../../library/char_utils.hpp"
#include "../../../../library/vector_utils.hpp"

class EquationElation {
public:
  void solveOne(std::string& equation) {
    for (int i = 0; i < equation.size(); i++)
      if (is_space(equation[i]))
        equation.erase(equation.begin() + i--);

    std::string eq;
    bool operand = false;
    if (is_unary_operator(equation.front())) {
      eq += equation.front();
      operand = true;
    }

    for (int i = operand ? 1 : 0; i < equation.size(); i++) {
      const char ch = equation[i];
      if (is_operand(ch)) {
        eq += SPACE;
        eq += ch;
        eq += SPACE;
        if (i + 1 < equation.size() && is_unary_operator(equation[i + 1])) {
          if (equation[i + 1] == MINUS) eq += MINUS;
          i += 1;
        }
      } else {
        eq += ch;
      }
    }

    std::stringstream sin(eq);
    std::vector<std::string> parts;
    for (std::string part; sin >> part; parts.emplace_back(part));

    auto is_plus_or_minus = [&](const std::string& str) {
      if (str.size() != 1) return false;
      return str.front() == PLUS || str.front() == MINUS;
    };

    auto is_multiply_or_divide = [&](const std::string& str) {
      if (str.size() != 1) return false;
      return str.front() == MULTI || str.front() == DIV;
    };

    out << parts << '\n';
    while (true) {
      auto it = std::find_if(parts.begin(), parts.end(), is_multiply_or_divide);
      if (it == parts.end()) {
        it = std::find_if(parts.begin(), parts.end(), is_plus_or_minus);
        if (it == parts.end()) break;
      }

      std::vector<std::string> n_parts;
      int at = it - parts.begin();
      for (int i = 0; i < at - 1; i++)
        n_parts.emplace_back(parts[i]);

      int r = solve(parts[at - 1], parts[at], parts[at + 1]);
      n_parts.emplace_back(std::to_string(r));

      for (int i = at + 2; i < parts.size(); i++)
        n_parts.emplace_back(parts[i]);

      parts.swap(n_parts);
      out << parts << '\n';
    }
  }

  void solve() {
    for (std::string equation; std::getline(in, equation); solveOne(equation));
  }

  EquationElation(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  int solve(const std::string& a, const std::string& op, const std::string& b) const {
    assert(op.length() == 1);
    const int ia = std::stoi(a);
    const int ib = std::stoi(b);
    if (char ch = op.front(); ch == PLUS)
      return ia + ib;
    else if (ch == MINUS) return ia - ib;
    else if (ch == MULTI) return ia * ib;
    else return ia / ib;
  }

  inline bool is_operand(const char ch) const {
    return ch == PLUS || ch == MINUS || ch == MULTI || ch == DIV || ch == EQ;
  }

  inline bool is_unary_operator(const char ch) const {
    return ch == PLUS || ch == MINUS;
  }

private:
  std::istream& in;
  std::ostream& out;

  const char PLUS = '+';
  const char MINUS = '-';
  const char MULTI = '*';
  const char DIV = '/';
  const char EQ = '=';
  const char SPACE = ' ';
};