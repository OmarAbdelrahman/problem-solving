#include <bits/stdc++.h>

using namespace std;

class LanguageDetection {
public:
  void solve() {
    int c = 1;
    for (string s; in >> s && s != "#"; c++) {
      out << "Case " << c << ": ";
      if (s == "HELLO")
        out << "ENGLISH";
      else if (s == "HOLA")
        out << "SPANISH";
      else if (s == "HALLO")
        out << "GERMAN";
      else if (s == "BONJOUR")
        out << "FRENCH";
      else if (s == "CIAO")
        out << "ITALIAN";
      else if (s == "ZDRAVSTVUJTE")
        out << "RUSSIAN";
      else
        out << "UNKNOWN";
      out << '\n';
    }
  }

  LanguageDetection(istream& in, ostream& out)
    : in(in), out(out) { }

private:
  ostream& out;
  istream& in;
};