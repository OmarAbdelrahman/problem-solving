#include "iostream"
#include "fstream"
#include "cstring"

using namespace std;

void solve(istream& in, ostream& out) {
  int sheet[30][4];
  for (int n; in >> n && n; ) {
    memset(sheet, 0, sizeof(sheet));
    int sheets = (n + 3) / 4;
    int page_count = 1;
    for (int i = 1; i <= sheets; i++) {
      sheet[i][1] = page_count++;
      if (page_count > n) break;
      sheet[i][2] = page_count++;
      if (page_count > n) break;
    }
    if (page_count <= n) {
      for (int i = sheets; i >= 1; i--) {
        sheet[i][3] = page_count++;
        if (page_count > n) break;
        sheet[i][0] = page_count++;
        if (page_count > n) break;
      }
    }
    out << "Printing order for " << n << " pages:" << '\n';
    for (int sh = 1; sh <= sheets; sh++) {
      if (sheet[sh][0] || sheet[sh][1]) {
        out << "Sheet " << sh << ", front: ";
        if (sheet[sh][0]) out << sheet[sh][0] << ", ";
        else out << "Blank, ";
        if (sheet[sh][1]) out << sheet[sh][1] << '\n';
        else out << "Blank" << '\n';
      }
      if (sheet[sh][2] || sheet[sh][3]) {
        out << "Sheet " << sh << ", back : ";
        if (sheet[sh][2]) out << sheet[sh][2] << ", ";
        else out << "Blank, ";
        if (sheet[sh][3]) out << sheet[sh][3] << '\n';
        else out << "Blank" << '\n';
      }
    }
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
