#include <bits/stdc++.h>
using namespace std;

struct suffix_array {

    suffix_array() = default;

    explicit suffix_array(const string& _s) {
        initialize(_s);
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

    void build_lcp() {
        assert(!c.empty() || !p.empty() || !s.empty());
        lcp = vector<int>(size() - 1);
        int k = 0;
        for (int i = 0; i < (int) lcp.size(); i++) {
            int pi = c[i];
            if (pi == 0) {
                continue;
            }
            int j = p[pi - 1];
            while (s[i + k] == s[j + k]) {
                k++;
            }
            lcp[pi - 1] = k;
            k = max(k - 1, 0);
        }
    }

    void build_phi_lcp() {
        assert(!p.empty() || !s.empty());
        vector<int> phi(size()), p_lcp(size());
        phi[p[0]] = -1;
        for (int i = 1; i < size(); i++) {
            phi[p[i]] = p[i - 1];
        }
        int k = 0;
        for (int i = 0; i < size(); i++) {
            if (phi[i] == -1) {
                p_lcp[i] = 0;
                continue;
            }
            while (s[i + k] == s[phi[i] + k]) {
                k++;
            }
            p_lcp[i] = k;
            k = max(k - 1, 0);
        }
        lcp = vector<int>(size() - 1);
        for (int i = 0; i < size() - 1; i++) {
            lcp[i] = p_lcp[p[i + 1]];
        }
    }

    string longest_common_substring(const string& a, const string& b) {
        initialize(a + char(DELIM - 1) + b);
        build();
        build_lcp();

        auto belong_to_different_strings = [&](const int ai, const int bi) {
            const int an = (int) a.size();
            return (ai <= an) != (bi <= an);
        };

        string r;
        int r_size = -1;
        for (int i = 1; i < size(); i++) {
            if (belong_to_different_strings(p[i], p[i - 1]) && lcp[i - 1] > r_size) {
                r_size = lcp[i - 1];
                r = s.substr(p[i], r_size);
            }
        }
        return r;
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

    int64_t count_different_substrings() {
        assert(!p.empty() || !lcp.empty());
        int64_t count = 0;
        for (int i = 1; i < size(); i++) {
            count += (int64_t) size() - 1 - p[i] - lcp[i - 1];
        }
        return count;
    }

    const vector<int>& get_lcp() const {
        assert(!lcp.empty());
        return lcp;
    }

    const vector<int>& get_suffix_array() const {
        assert(!p.empty());
        return p;
    }

    const string& str() const {
        assert(!s.empty());
        return s;
    }

    int size() const {
        return (int) s.size();
    }

private:
    void initialize(const string& _s) {
        s = _s + DELIM;
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
            c[p[i]] = c[p[i - 1]] + (int) (s[p[i]] != s[p[i - 1]]);
        }
    }

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

    const char DELIM = char(31);
};

struct suffix {
    int index;
    pair<int, int> rank;

    suffix(): index(-1), rank({}) { }

    suffix(const int i, const pair<int, int>& r): index(i), rank(r) { }

    bool operator < (const suffix& o) const {
        return rank < o.rank;
    }
};

/**
 * Returns the suffix array of a given string.
 * @param s - given string "make sure to concat '$'" to s
 * @return vector<int>
 */
vector<int> suffix_array(const string& s) {
    int n = (int) s.size();
    int m = n;
    while ((m & (m - 1)) != 0) {
        m++;
    }
    vector<suffix> sa(n);
    vector<vector<int>> rank(1, vector<int>(n));
    for (int i = 0; i < n; i++) {
        rank[0][i] = s[i] - '.';
    }
    for (int k = 1; 1 << k <= m; k++) {
        rank.emplace_back(n);
        for (int i = 0; i < n; i++) {
            sa[i] = suffix(i, { rank[k - 1][i], rank[k - 1][(i + (1 << (k - 1))) % n] });
        }
        sort(begin(sa), end(sa));
        rank[k][sa[0].index] = 0;
        for (int i = 1; i < n; i++) {
            rank[k][sa[i].index] = sa[i].rank == sa[i - 1].rank ? rank[k][sa[i - 1].index] : i;
        }
    }
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = sa[i].index;
    }
    return r;
}

vector<int> suffix_array_less_memory(const string& s) {
    int n = s.size();
    vector<int> p(n), c(n);
    vector<suffix> sa(n);
    {
        for (int i = 0; i < n; i++) {
            sa[i] = suffix(i, {s[i] - 'a', s[i] - 'a'});
        }
        sort(begin(sa), end(sa));
        for (int i = 0; i < n; i++) {
            p[i] = sa[i].index;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            c[p[i]] = c[p[i - 1]] + (int) !(sa[i].rank == sa[i - 1].rank);
        }
    }
    {
        for (int k = 0; 1 << k < n; k++) {
            for (int i = 0; i < n; i++) {
                sa[i] = suffix(i, { c[i], c[(i + (1 << k)) % n] });
            }
            sort(begin(sa), end(sa));
            for (int i = 0; i < n; i++) {
                p[i] = sa[i].index;
            }
            c[p[0]] = 0;
            for (int i = 1; i < n; i++) {
                c[p[i]] = c[p[i - 1]] + (int) !(sa[i].rank == sa[i - 1].rank);
            }
        }
    }
    return p;
}

void count_sort(vector<int>& p, const vector<int>& c) {
    const int n = (int) p.size();
    vector<int> count(n);
    for (const int& ci : c) {
        count[ci]++;
    }
    vector<int> new_p(n);
    for (int i = 1; i < n; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        new_p[--count[c[p[i]]]] = p[i];
    }
    p.swap(new_p);
}

vector<int> suffix_array_fast(const string& s) {
    const int n = (int) s.size();
    vector<int> p(n), c(n);
    vector<int> count(300, 0);

    for (const char& si : s) {
        count[si]++;
    }
    for (int i = 1; i < (int) count.size(); i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        p[--count[s[i]]] = i;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        c[p[i]] = c[p[i - 1]] + (int) (s[p[i]] != s[p[i - 1]]);
    }

    for (int k = 0; 1 << k < n; k++) {
        for (int i = 0; i < n; i++) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        count_sort(p, c);
        vector<int> new_c(n);
        new_c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            pair<int, int> nr = { c[p[i]], c[(p[i] + (1 << k)) % n] };
            pair<int, int> pr = { c[p[j]], c[(p[j] + (1 << k)) % n] };
            new_c[p[i]] = new_c[p[i - 1]] + (int) (nr != pr);
        }
        c.swap(new_c);
    }
    return p;
}

int main() {
  return 0;
}