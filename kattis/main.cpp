#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include <unordered_map>
#include "../library/lib.hpp"
#include "../library/suffix_array.hpp"

using namespace std;

void solve(istream& in, ostream& out) {
  for (int n; in >> n; ) {
    vector<string> dictionary(n);
    in >> dictionary;
    unordered_map<int, string> word;
    unordered_map<string, int> label;
    for (int i = 0; i < n; i++) {
      word[i + 1] = dictionary[i];
      label[dictionary[i]] = i + 1;
    }
    sort(begin(dictionary), end(dictionary), [&](const string& a, const string& b) -> bool {
      if (a.length() != b.length()) return a.length() < b.length();
      if (a != b) return a < b;
      return label[a] < label[b];
    });
    for (int i = 1; i < n ; i++) {
      dictionary[0] += dictionary[i];
    }
    suffix_array_t sa(dictionary.front());
    const vector<int>& lcp = sa._lcp();
    for (int i = 0; i < sa.size(); i++) {
      out << i << ' ' << lcp[i] << ' ' << sa[i] << ' ' << sa.suffix(i) << endl;
    }
    int q;
    in >> q;
    for (string s; q-- != 0; ) {
      in >> s;
      out << s << endl;
      print_pretty_pair(out, sa.find_interval_of(s), true);
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ifstream fin(R"(C:\Users\omara\CLionProjects\problem-solving\kattis\in.txt)");
  istream& in(std::cin);
  ostream& out(std::cout);
  solve(fin, out);
  fin.close();
  return 0;
}