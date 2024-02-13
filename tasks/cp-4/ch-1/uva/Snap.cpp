#include <bits/stdc++.h>

using namespace std;

class Snap {
public:
  void solve() {
    int nt;
    in >> nt;
    for (int _ = 0; _ < nt; _++) {
      if (_) out << '\n';
      string jane, john;
      in >> jane >> john;
      deque<char> down_jane, down_john;
      for (const char& ch : jane) {
        down_jane.push_back(ch);
      }
      for (const char& ch : john) {
        down_john.push_back(ch);
      }
      deque<char> up_jane, up_john;
      string result;
      for (int turn = 0; turn < MAX; turn++) {
        char ja = down_jane.front();
        down_jane.pop_front();
        up_jane.push_front(ja);
        char jo = down_john.front();
        down_john.pop_front();
        up_john.push_front(jo);
        if (ja == jo) {
          int snap = random() / 141 % 2;
          if (snap) {
            while (!up_jane.empty()) {
              up_john.push_front(up_jane.back());
              up_jane.pop_back();
            }
            out << "Snap! for John: ";
            for (const char& ch : up_john) out << ch;
            out << '\n';
          } else {
            while (!up_john.empty()) {
              up_jane.push_front(up_john.back());
              up_john.pop_back();
            }
            out << "Snap! for Jane: ";
            for (const char& ch : up_jane) out << ch;
            out << '\n';
          }
        }
        if (down_jane.empty() && up_jane.empty()) {
          result = "John wins.";
          break;
        }
        if (down_john.empty() && up_john.empty()) {
          result = "Jane wins.";
          break;
        }
        if (down_john.empty()) {
          while (!up_john.empty()) {
            down_john.push_front(up_john.front());
            up_john.pop_front();
          }
        }
        if (down_jane.empty()) {
          while (!up_jane.empty()) {
            down_jane.push_front(up_jane.front());
            up_jane.pop_front();
          }
        }
      }
      if (result.empty()) {
        out << "Keeps going and going ..." << '\n';
      } else {
        out << result << '\n';
      }
    }
  }

  Snap(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;

  const int MAX = 1000;
};