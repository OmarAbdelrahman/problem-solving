#include "iostream"
#include "fstream"
#include "vector"
#include "algorithm"
#include "iomanip"

using namespace std;

void solve(istream& in, ostream& out) {
  while (true) {
    vector<int> v(3);
    in >> v[0] >> v[1] >> v[2];

    if (count(begin(v), end(v), 0) == 3)
      break;

    while (v.back() != 0) {
      v.emplace_back(-1);
      in >> v.back();
    }
    v.pop_back();

    int r = -1;
    for (int t = 1; t <= 18000; t++) {
      int c = 0, o = -1;
      for (int i = 0; i < (int)v.size(); i++) {
        if (t % (2 * v[i]) < (v[i] - 5)) {
          c += 1;
        }
        if (v[i] < t) o += 1;
      }
      if (c == int(v.size()) && o >= 0) {
        r = t;
        break;
      }
    }

    if (r == -1) {
      out << "Signals fail to synchronise in 5 hours" << '\n';
    } else {
      int hours = r / 3600;
      r %= 3600;
      int minutes = r / 60;
      r %= 60;
      int seconds = r;
      out << setw(2) << setfill('0') << hours << ':'
          << setw(2) << minutes << ':'
          << setw(2) << seconds << '\n';
    }
  }
}

int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifndef ONLINE_JUDGE
  ifstream fin(R"(/Users/omarabdelrahman/Development/cpp-playground/cpp-playground/in.txt)");
  solve(fin, cout);
  fin.close();
#else
  solve(cin, cout);
#endif

  return 0;
}
