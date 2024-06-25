#include <iostream>
#include <string>

class DivideBy100 {
public:
  void solve() {
    std::string N, M;
    in >> N >> M;
    if (M == "1") {
      out << N << '\n';
      return;
    }
    int ni = N.length() - 1;
    int mi = M.length() - 1;
    while (ni >= 0 && mi >= 0 && N[ni] == '0' && M[mi] == '0') {
      N[ni] = '?';
      ni -= 1;
      mi -= 1;
    }
    if (ni < mi) {
      out << "0.";
      mi -= (ni + 1);
      while (mi >= 0 && M[mi] == '0') {
        out << '0';
        mi -= 1;
      }
      for (int i = 0; i <= ni && N[i] != '?'; i++) {
        out << N[i];
      }
      out << '\n';
    } else {
      int dot_at = ni;
      while (mi >= 0 && M[mi] == '0') {
        dot_at -= 1;
        mi -= 1;
      }
      for (int i = 0; i <= ni; i++) {
        out << N[i];
        if (i == dot_at && i != ni) {
          out << '.';
        }
      }
      out << '\n';
    }
  }

  DivideBy100(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;
};