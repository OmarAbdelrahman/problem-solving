template<typename T>
inline static T power(const T a, const T b) {
  assert(b >= 0);
  T x = a, res = 1;
  T p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template<typename T>
inline static T gcd(T a, T b) {
  while (b > 0) {
    T t = a % b;
    a = b;
    b = t;
  }
  return a;
}

inline int negative_mod(const int a, const int mod) {
  return (a % mod + mod) % mod;
}

[[nodiscard]] constexpr auto floor_modulo(auto dividend, auto divisor) {
  return ((dividend % divisor) + divisor) % divisor;
}

inline int sum_of_digits_sum_to(const int n) {
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

std::vector<int> pre_compute_sum_of_digits_sum_to(const int n) {
  std::vector<int> sum(n + 1, 0)
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

struct fraction_t {
  int p;
  int q;

  fraction_t(): p(0), q(1) { }

  fraction_t(int _p, int _q) {
    int g = gcd(_p, _q);
    _p /= g;
    _q /= g;
    if (_q < 0) {
      _p = -_p;
      _q = -_q;
    }
    p = _p;
    q = _q;
  }

  fraction_t& operator+=(const fraction_t& other) {
    p += other.p;
    q += other.q;
    return *this;
  }

  fraction_t median(const fraction_t& f) const {
    return fraction_t(p + f.p, q + f.q);
  }

  bool operator<(const fraction_t& other) const {
    return p * other.q < other.p * q;
  }
};