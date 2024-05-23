template<class T>
inline static T power(const T& a, const T& b) {
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

inline int negative_mod(const int a, const int b) {
  return (a % b + b) % b;
}
