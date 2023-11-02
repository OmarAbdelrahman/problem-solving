#include <bits/stdc++.h>
using namespace std;

class AGoalsOfVictory {
public:
    void solveOne(istream &is, ostream &os) {
        int n; is >> n;
        vector<int> a(n - 1);
        for (int& ai : a) {
            is >> ai;
        }
        os << -accumulate(begin(a), end(a), 0) << '\n';
    }

    void solve(istream &is, ostream &os) {
        int t; is >> t;
        for (int i = 0; i < t; i++) {
            solveOne(is, os);
        }
    }
};