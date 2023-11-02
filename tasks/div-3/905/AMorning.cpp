#include <bits/stdc++.h>
using namespace std;

class AMorning {
public:
    void solveOne(istream &is, ostream &os) {
        string c; is >> c;

        int r = 4, j = 1;
        for (int i = 0; i < 4; i++) {
            int d = c[i] - '0';
            if (d == 0) {
                d = 10;
            }
            r += abs(j - d);
            j = d;
        }
        os << r << '\n';
    }

    void solve(istream &is, ostream &os) {
        int t; is >> t;
        for (int i = 0; i < t; i++) {
            solveOne(is, os);
        }
    }
};