#include "iostream"
#include "fstream"
#include "iomanip"
#include "sstream"

using namespace std;

void solve(istream& in, ostream& out) {
  string s;
  int m;
  
  while (in >> s >> m) {
    if (s == "0" && m == 0) break;
   
    stringstream ss;
    ss << s;
    int i;
    if (s[0] == '0' && s[1] == 'x')
      ss >> hex >> i;
    else if (s[0] == '0')
      ss >> oct >> i;
    else
      ss >> dec >> i;
    
    int r = 0, val;
    while (m--) {
      string cmd;
      in >> cmd >> val;
      
      if (cmd == "i--") {
        r += val == i;
        if (val != i) i = val;
        i--;
      } else if (cmd == "++i") {
        ++i;
        r += val == i;
        if (val != i) i = val;
      } else if (cmd == "i++") {
        r += val == i;
        if (val != i) i = val;
        i++;
      } else if (cmd == "--i") {
        --i;
        r += val == i;
        if (val != i) i = val;
      } else {
        r += val == i;
        if (val != i) i = val;
      }
    }
    
    out << r << '\n';
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
