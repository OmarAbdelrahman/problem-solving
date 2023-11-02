#include <bits/stdc++.h>
using namespace std;

class ASumOfThree {
public:
    void solveOne(istream &is, ostream &os) {
        int n; is >> n;
        for (int i = 1; i <= 10; i++) {
            if (i % 3 == 0) {
                continue;
            }
            for (int j = i + 1; j <= 10; j++) {
                if (j % 3 == 0) {
                    continue;
                }
                int z = n - i - j;
                if (z > 0 && z % 3 != 0 && z != j && z != i) {
                    os << "YES" << '\n';
                    os << i << ' ' << j << ' ' << z << '\n';
                    return;
                }
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