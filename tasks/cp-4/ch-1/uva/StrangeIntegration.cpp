#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

#include "../../../../library/char_utils.hpp"
#include "../../../../library/string_utils.hpp"

class StrangeIntegration {
private:
  struct expression_t {
    std::string L, op, R;

    expression_t() = default;
    expression_t(std::string l, std::string _op, std::string r)
      : L(std::move(l)), op(std::move(_op)), R(std::move(r)) { }

    expression_t simplify(std::unordered_map<std::string, expression_t>& value) {
      if (is_digit_L() && is_digit_R()) return *this;
      if (is_digit_L()) return simplify_R(value[R]);
      if (is_digit_R()) return simplify_L(value[L]);
      return simplify(value[L], value[R]);
    }

    std::string to_string() const { return L + op + R; }

  private:
    expression_t simplify(const expression_t& left, const expression_t& right) {
      L = left.to_string();
      R = right.to_string();
      if (is_plus()) {
        if (right.is_plus()) R = put_brackets(R);
      } else {
        if (left.is_plus()) {
          L = put_brackets(L);
          R = put_brackets(R);
        } else {
          R = put_brackets(R);
        }
      }
      return *this;
    }

    expression_t simplify_R(const expression_t& right) {
      R = right.to_string();
      if (!(is_plus() && right.is_multiply())) R = put_brackets(R);
      return *this;
    }

    expression_t simplify_L(const expression_t& left) {
      L = left.to_string();
      if (is_multiply() && left.is_plus()) L = put_brackets(L);
      return *this;
    }

    inline bool is_digit_L() const { return is_digit(L[0]); }
    inline bool is_digit_R() const { return is_digit(R[0]); }
    inline bool is_plus() const { return op[0] == '+'; }
    inline bool is_multiply() const { return !is_plus(); }
  };

public:
  void solveOne(const int case_i, const int n) {
    std::unordered_map<std::string, expression_t> value;
    std::string variable, eq, left, op, right;
    for (int i = 0; i < n; i++) {
      in >> variable >> eq >> left >> op >> right;
      value[variable] = expression_t(left, op, right).simplify(value);
    }
    out << "Expression #" << case_i << ": " << value[variable].to_string() << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1, n; _ <= nt; _++) {
      in >> n;
      solveOne(_, n);
    }
  }

  StrangeIntegration(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  static std::string put_brackets(const std::string& str) { return '(' + str + ')'; }

private:
  std::istream& in;
  std::ostream& out;
};