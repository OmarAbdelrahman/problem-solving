#ifndef SPARSE_TABLE
#define SPARSE_TABLE

template <typename T, class F = std::function<T(T&&, T&&)>>
struct sparse_table {
  sparse_table(const std::vector<T>& a, F&& f) : func(std::forward<F>(f)) {
    n = a.size();
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(const int from, const int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }

private:
  int n;
  std::vector<std::vector<T>> mat;
  F func;
};

#endif
