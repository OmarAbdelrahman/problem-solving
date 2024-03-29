#include "iostream"
#include "fstream"
#include "vector"
#include "string"
#include "unordered_map"

void solve(std::istream& in, std::ostream& out) {
  for (int bs, vs; in >> bs >> vs; ) {
    std::vector<int> sizes(vs);
    std::unordered_map<std::string, int> index;

    for (int i = 0; i < vs; i++) {
      std::string name;
      in >> name >> sizes[i];
      index[name] = i;
    }

    std::vector<uint64_t> values(vs, 0);
    for (int i = 0; i < vs; i++) {
      std::string binary;
      for (int j = 0; j < sizes[i]; j++) {
        std::string bi;
        in >> bi;
        binary += bi;
      }
      const int size = bs * sizes[i];
      for (int j = 0; j < size; j++) {
        if (binary[j] == '1') {
          values[i] |= (UINT64_C(1) << (size - j - 1));
        }
      }
    }

    int queries;
    in >> queries;
    while (queries--) {
      std::string var;
      in >> var;
      if (index.find(var) == index.end()) {
        out << var << '=' << '\n';
      } else {
        out << var << '=' << values[index[var]] << '\n';
      }
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
