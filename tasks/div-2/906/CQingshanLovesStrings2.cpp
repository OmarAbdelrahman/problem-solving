#include <bits/stdc++.h>
using namespace std;

#define _size(a) (int) (a).size()

class CQingshanLovesStrings2 {
public:
  void solveOne(istream& in, ostream& out) {
    int n;
    in >> n;
    string s;
    in >> s;
    int os = 0, fs = 0;
    for (const char& ch : s) {
      os += (int) ch == '0';
      fs += (int) ch == '1';
    }
    if (n % 2 != 0 || os != fs) {
      out << -1 << '\n';
      return;
    }
    vector<int> r;
    deque<char> q;
    for (const char& ch : s) {
      q.push_back(ch);
    }
    int i = 0;
    while (!q.empty()) {
      if (q.front() == q.back()) {
        if (q.front() == '1') {
          q.push_front('1');
          q.push_front('0');
          r.emplace_back(i);
        } else {
          q.push_back('0');
          q.push_back('1');
          r.emplace_back(n - i);
        }
        n += 2;
      }
      while (!q.empty() && q.front() != q.back()) {
        q.pop_back();
        q.pop_front();
        i += 1;
      }
    }
    out << _size(r) << '\n';
    copy(begin(r), end(r), ostream_iterator<int>(out, " "));
    out << '\n';
  }

  void solve(istream& in, ostream& out) {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne(in, out);
    }
  }
};