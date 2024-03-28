#include "iostream"
#include "fstream"

void solve(std::istream& in, std::ostream& out) {
  int tt;
  in >> tt;
  while (tt--) {
    int64_t s, d;
    in >> s >> d;
    if (s < d || (s + d) % 2 != 0) {
      out << "impossible" << '\n';
    } else {
      out << (s + d) / 2 << " " << (s - d) / 2 << "\n";
    }
  }
}

int main(int argc, const char* argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

#ifndef ONLINE_JUDGE
  std::ifstream fin(R"(/Users/omarabdelrahman/Development/cpp-playground/cpp-playground/in.txt)");
  solve(fin, std::cout);
  fin.close();
#else
  solve(std::cin, std::cout);
#endif

  return 0;
}
