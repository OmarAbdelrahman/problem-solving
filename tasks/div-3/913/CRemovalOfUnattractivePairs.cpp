#include <bits/stdc++.h>

using namespace std;

class CRemovalOfUnattractivePairs {
public:
  void solveOne() {
    int n;
    in >> n;
    string s;
    in >> s;
    vector<int> freq(26);
    for (const char ch : s) {
      freq[ch - 'a']++;
    }
    int big = *max_element(begin(freq), end(freq));
    if (2 * big >= n) {
      out << 2 * big - n << '\n';
    } else {
      out << n % 2 << '\n';
    }
  }

  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      solveOne();
    }
  }

  CRemovalOfUnattractivePairs(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};