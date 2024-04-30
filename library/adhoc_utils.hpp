inline int sum_of_digits_sum_to(const int& n) {
  if (n < 10) return n * (n + 1) / 2;
  const int d = (int) std::log10(n);
  std::vector<int> a(d + 1, 0);
  a[0] = 0, a[1] = 45;
  for (int i = 2; i <= d; i++) {
    a[i] = a[i - 1] * 10 + 45 * std::ceil(std::pow(10, i - 1));
  }
  const int p = std::ceil(std::pow(10, d));
  const int msd = n / p;
  return msd * a[d] + (msd * (msd - 1) / 2) * p + msd * (1 + n % p) + sum_of_digits_sum_to(n % p);
}

std::vector<int> pre_compute_sum_of_digits_sum_to(const int& n) {
  std::vector<int> sum(n + 1, 0);
  sum[1] = 1;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1];
    int v = i;
    while (v > 0) {
      sum[i] += v % 10;
      v /= 10;
    }
  }
  return sum;
}
