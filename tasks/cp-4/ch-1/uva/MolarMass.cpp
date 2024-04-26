#include "iostream"
#include "fstream"
#include "iomanip"
#include "unordered_map"

using namespace std;

void solve(istream& in, ostream& out) {
  unordered_map<char, double> value;
  value['C'] = 12.01;
  value['H'] = 1.008;
  value['O'] = 16.00;
  value['N'] = 14.01;
  int tt;
  in >> tt;
  while (tt--) {
    string s;
    in >> s;
    int n = int(s.size());
    double r = 0.0;
    for (int i = 0; i < n; i++) {
      if (!isdigit(s[i])) {
        int v = 1;
        if (i + 1 < n && isdigit(s[i + 1])) {
          v = s[i + 1] - '0';
          if (i + 2 < n && isdigit(s[i + 2])) {
            v = v * 10 + (s[i + 2] - '0');
          }
        }
        r += (v * value[s[i]]);
      }
    }
    out << fixed << setprecision(3) << r << '\n';
  }
}

int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
//  ifstream fin(R"(/Users/omarabdelrahman/Development/cpp-playground/cpp-playground/in.txt)");
//  solve(fin, cout);
//  fin.close();
  
  solve(cin, cout);
  return 0;
}
