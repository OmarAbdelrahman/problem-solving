#include <bits/stdc++.h>
using namespace std;

class ADontTryToCount {
public:
    void solveOne(istream &is, ostream &os) {
        int n, m;
        is >> n >> m;

        string x, s;
        is >> x >> s;

        for (int i = 0; i < 6; i++) {
            if (x.find(s) != string::npos) {
                os << i << '\n';
                return;
            }
            x += x;
        }

        os << -1 << '\n';
    }

    void solve(istream &is, ostream &os) {
        int t; is >> t;
        for (int i = 0; i < t; i++) {
            solveOne(is, os);
        }
    }
};