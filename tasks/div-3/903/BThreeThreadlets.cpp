#include <bits/stdc++.h>
using namespace std;

class BThreeThreadlets {
public:
    void solveOne(istream &is, ostream &os) {
        vector<int> a(3);
        is >> a[0] >> a[1] >> a[2];

        auto all = [&]() -> bool {
            for (int i = 1; i < (int) a.size(); i++) {
                if (a[i] != a[i - 1]) {
                    return false;
                }
            }
            return true;
        };

        if (all()) {
            os << "YES" << '\n';
            return;
        }

        for (int i = 0; i < 3; i++) {
            sort(begin(a), end(a));
            a.back() -= a.front();
            a.push_back(a.front());
            if (all()) {
                os << "YES" << '\n';
                return;
            }
        }

        os << "NO" << '\n';
    }

    void solve(istream &is, ostream &os) {
        int t; is >> t;
        for (int i = 0; i < t; i++) {
            solveOne(is, os);
        }
    }
};