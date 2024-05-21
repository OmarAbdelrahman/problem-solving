#include <iostream>
#include <string>
#include <vector>
#include <array>

class MobileSMS {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 1; _ <= nt; _++) {
      int n;
      in >> n;
      std::vector<int> button(n);
      for (int& a : button) in >> a;
      for (int i = 0; i < n; i++) {
        int freq;
        in >> freq;
        out << phone[button[i]][freq - 1];
      }
      out << '\n';
    }
  }

  MobileSMS(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  static const int BUTTONS = 10;

  std::array<std::string, BUTTONS> phone = {
    " ",
    ".,?\"",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
  };
};