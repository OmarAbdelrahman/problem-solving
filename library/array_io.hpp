template<typename T, std::size_t Size>
std::istream& operator >> (std::istream& in, std::array<T, Size>& a) {
  for (T& it : a) in >> it;
  return in;
}

template<typename T, std::size_t Size>
std::ostream& operator << (std::ostream& out, const std::array<T, Size>& a) {
  for (int i = 0; i < Size; i++) {
    if (i > 0) out << ' ';
    out << a[i];
  }
  return out;
}
