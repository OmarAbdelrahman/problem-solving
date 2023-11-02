#include <bits/stdc++.h>
using namespace std;

struct suffix_array {

    suffix_array(const string& _s) {
        s = _s + "$";
        const int n = (int) s.size();
        p = vector<int>(n);
        c = vector<int>(n);
        vector<int> count(300, 0);
        for (const char& si : s) {
            count[si]++;
        }
        for (int i = 1; i < (int) count.size(); i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            p[--count[s[i]]] = i;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            c[p[i]] = c[p[i - 1]] + (int) (s[p[i]] != s[p[i - 1]]);
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
                new_c[p[i]] = new_c[p[i - 1]] + (int) (rn != pr);
            }
            c.swap(new_c);
        }
    }

    int find_first_of(const string& substring) {
        const int m = (int) substring.size();
        int l = 0, r = size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int value = strncmp(s.c_str() + p[mid], substring.c_str(), m);
            if (value >= 0) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (strncmp(s.c_str() + p[l], substring.c_str(), m) != 0) {
            return -1;
        }
        return l;
    }

    pair<int, int> find_interval_of(const string& substring) {
        const int i = find_first_of(substring);
        if (i == -1) {
            return { -1, -1 };
        }
        const int m = (int) substring.size();
        int l = 0, r = size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int value = strncmp(s.c_str() + p[mid], substring.c_str(), m);
            if (value > 0) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (strncmp(s.c_str() + p[r], substring.c_str(), m) != 0) {
            return { i, r - 1 };
        }
        return { i, r };
    }

    int occurrences_of(const string& substring) {
        const pair<int, int> interval = find_interval_of(substring);
        if (interval.first == -1) {
            return 0;
        }
        return interval.second - interval.first + 1;
    }

    int& operator[](int i) {
        assert(i >= 0 && i < size());
        return p[i];
    }

    const int& operator[](int i) const {
        assert(i >= 0 && i < size());
        return p[i];
    }

    int size() const {
        return (int) p.size();
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

    vector<int> p, c;
    string s;
};

class ASubstringSearch {
public:
    void solveOne(istream &is, ostream &os) {
        string s; is >> s;

        suffix_array sa(s);
        sa.build();

        int q; is >> q;
        while (q-- != 0) {
            string p; is >> p;
            int r = sa.find_first_of(p);
            if (r != -1) {
                os << "Yes" << '\n';
            } else {
                os << "No" << '\n';
            }
        }
    }

    void solve(istream &is, ostream &os) {
        solveOne(is, os);
    }
};