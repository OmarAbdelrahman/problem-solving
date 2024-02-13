#include <bits/stdc++.h>
#include "../library/vector_io.hpp"
#include "../library/pair_io.hpp"
#include "../library/suffix_array.hpp"
#include "../library/array_io.hpp"

using namespace std;

//template<class T, class S>
//ostream& operator << (ostream &o, const pair<T, S> &p) {
//  return o << '(' << p.first << ", " << p.second << ')';
//}
//template<template<class, class...> class T, class... A>
//typename enable_if<!is_same<T<A...>, string>(), ostream&>::type
//operator << (ostream &o, T<A...> V) {
//  o << '[';
//  for(auto a : V) o << a << ", ";
//  return o << ']';
//}

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
      print_pretty_pair(out, sa.find_interval_of(s));
    }
  }
}

inline bool is_perfect_square(int64_t x) {
  int64_t sr = int64_t(round(sqrt(x)));
  return (sr * sr == x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  /*ifstream fin(R"(C:\Users\omara\CLionProjects\problem-solving\kattis\in.txt)");
  istream& in(std::cin);
  ostream& out(std::cout);
  solve(fin, out);
  fin.close();*/

  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if ((dx == 0) ^ (dy == 0)) {
        cout << "a= ";
        print_pretty_pair<int, int>(cout, {dx, dy});
      }
      if (dx != 0 && dy != 0) {
        cout << "b= ";
        print_pretty_pair<int, int>(cout, {dx, dy});
      }
    }
  }
  return 0;
}