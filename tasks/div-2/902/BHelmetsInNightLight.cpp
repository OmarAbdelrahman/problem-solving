#include <bits/stdc++.h>
using namespace std;

class BHelmetsInNightLight {
public:
    void solveOne(istream &is, ostream &os) {
        int n, p; is >> n >> p;
        vector<int> a(n), b(n);
        for (int& ai : a) {
            is >> ai;
        }
        for (int& bi : b) {
            is >> bi;
        }
        vector<pair<int, int>> abs(n);
        for (int i = 0; i < n; i++) {
            abs[i] = { b[i], a[i] };
        }
        sort(begin(abs), end(abs));
        int64_t r = 0, m = n;
        for (int i = 0; i < n - 1 && m > 1; i++) {
            if (abs[i].first > p) {
                break;
            }
            if (m - abs[i].second <= 0) {
                r += (m - 1) * abs[i].first;
                m = 1;
                break;
            }
            r += (int64_t) (abs[i].first * abs[i].second);
            m -= abs[i].second;
        }
        os << r + m * p << '\n';
    }

    void solve(istream &is, ostream &os) {
        int t; is >> t;
        for (int i = 0; i < t; i++) {
            solveOne(is, os);
        }
    }
};