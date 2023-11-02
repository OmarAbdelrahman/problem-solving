#include <bits/stdc++.h>
using namespace std;

class BChemistry {
public:
    void solveOne(istream &is, ostream &os) {
        int n, k;
        is >> n >> k;
        string s; is >> s;

        vector<int> freq(26, 0);
        for (const char& ch : s) {
            freq[ch - 'a']++;
        }

        int odds = 0;
        for (const int& c : freq) {
            odds += c & 1;
        }
        os << ((odds <= k + 1) ? "YES" : "NO") << '\n';
    }

    void solve(istream &is, ostream &os) {
        int t; is >> t;
        for (int i = 0; i < t; i++) {
            solveOne(is, os);
        }
    }
};