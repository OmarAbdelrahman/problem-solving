#include <iostream>
#include <vector>
#include <string>

class DHieroglyphsDecoder {
private:
  void visualize_input(const std::vector<std::string>& code) {
    for (int i = 1; i + 1 < N; i++) {
      std::cerr << i;
      for (size_t j = 1; j + 1 < code[i].size(); j++) {
        if (code[i][j] == R) std::cerr << ' ' << 0; else std::cerr << ' ' << 1;
      }
      std::cerr << ' ' << (1 << (i - 1));
      std::cerr << std::endl;
    }
    std::cerr << std::endl;
  }

public:
  void solveOne(const std::vector<std::string>& code) {
    const int m = code[0].size();
    std::string message;
    for (int j = 1; j + 1 < m; j++) {
      int ascii = 0;
      for (int i = 1; i + 1 < N; i++) {
        if (code[i][j] == L)
          ascii += (1 << (i - 1));
      }
      message += char(ascii);
    }
    out << message << '\n';
  }

  void solve() {
    int nt;
    in >> nt;
    while (nt--) {
      std::vector<std::string> code(N);
      for (std::string& row : code) in >> row;
      solveOne(code);
    }
  }

  DHieroglyphsDecoder(std::istream& in, std::ostream& out)
    : in(in), out(out) { }

private:
  std::istream& in;
  std::ostream& out;

  const int N = 10;
  const char R = '/';
  const char L = '\\';
};