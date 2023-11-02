#include <bits/stdc++.h>
using namespace std;

struct suffix_array {

    suffix_array(const string& _s) {
        s = _s + "$";
        p = vector<int>(size());
        c = vector<int>(size());
        vector<int> count(300, 0);
        for (const char& si : s) {
            count[si]++;
        }
        for (int i = 1; i < (int) count.size(); i++) {
            count[i] += count[i - 1];
        }
        for (int i = size() - 1; i >= 0; i--) {
            p[--count[s[i]]] = i;
        }
        c[p[0]] = 0;
        for (int i = 1; i < size(); i++) {
            c[p[i]] = c[p[i - 1]] + (int)(s[p[i]] != s[p[i - 1]]);
        }
    }

    void build() {
        for (int k = 0; 1 << k < size(); k++) {
            for (int i = 0; i < size(); i++) {
                p[i] = (p[i] - (1 << k) + size()) % size();
            }
            count_sort();
            vector<int> new_c(size());
            new_c[p[0]] = 0;
            for (int i = 1; i < size(); i++) {
                const int j = i - 1;
                pair<int, int> rn = { c[p[i]], c[(p[i] + (1 << k)) % size()] };
                pair<int, int> pr = { c[p[j]], c[(p[j] + (1 << k)) % size()] };
                new_c[p[i]] = new_c[p[i - 1]] + (int)(rn != pr);
            }
            c.swap(new_c);
        }
    }

    void build_lcp() {
        assert(!c.empty() || !p.empty() || !s.empty());
        lcp = vector<int>(size() - 1);
        int k = 0;
        for (int i = 0; i < (int) lcp.size(); i++) {
            int pi = c[i];
            int j = p[pi - 1];
            while (s[i + k] == s[j + k]) {
                k++;
            }
            lcp[pi - 1] = k;
            k = max(k - 1, 0);
        }
    }

    int64_t count_different_substrings() {
        assert(!p.empty() || !lcp.empty());
        int64_t count = 0;
        for (int i = 1; i < size(); i++) {
            count += (int64_t) size() - 1 - p[i] - lcp[i - 1];
        }
        return count;
    }

    int size() const {
        return (int) s.size();
    }

private:
    void count_sort() {
        vector<int> count(size(), 0);
        for (const int& ci : c) {
            count[ci]++;
        }
        for (int i = 1; i < size(); i++) {
            count[i] += count[i - 1];
        }
        vector<int> new_p(size());
        for (int i = size() - 1; i >= 0; i--) {
            new_p[--count[c[p[i]]]] = p[i];
        }
        p.swap(new_p);
    }

    vector<int> lcp;
    vector<int> p, c;
    string s;
};

class ANumberOfDifferentSubstrings {
public:
    void solveOne(istream &is, ostream &os) {
        string s; is >> s;

        suffix_array sa(s);
        sa.build();
        sa.build_lcp();

        os << sa.count_different_substrings() << '\n';
    }

    void solve(istream &is, ostream &os) {
        solveOne(is, os);
    }
};