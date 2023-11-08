#include <bits/stdc++.h>
using namespace std;

template<typename U, typename V>
ostream& operator << (ostream& out, const pair<U, V>& p) {
  return out << '{' << p.first << ", " << p.second << '}';
}

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
  const int n = static_cast<int>(v.size());
  for (int i = 0; i < n; i++) {
    out << v[i] << " \n"[i == n - 1];
  }
}