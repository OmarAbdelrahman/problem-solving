#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "array"
#include "vector"
#include "algorithm"

const int N = 12;

void solve(std::istream& in, std::ostream& out) {
  const std::array<std::string, N> notes{"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
  const std::array<bool, N> major{1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1};

  for (std::string s; std::getline(in, s) && s != "END"; ) {
    std::stringstream ss(s);
    std::vector<bool> used(N, false);

    for (std::string note; ss >> note; ) {
      int at = std::find(notes.begin(), notes.end(), note) - notes.begin();
      used[at] = true;
    }

    int n = 0;
    for (int i = 0; i < N; i++) {
      bool is_major = true;
      for (int j = 0; j < N; j++) {
        if (used[(i + j) % N] && !major[j]) {
          is_major = false;
          break;
        }
      }

      if (is_major) {
        std::cout << (n++ ? " " : "") << notes[i];
      }
    }

    std::cout << '\n';
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
