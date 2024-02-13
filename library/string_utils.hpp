std::vector<std::string> substrings_slow(const std::string& str) {
  const uint32_t n = std::size(str);
  std::vector<std::string> subs;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n - i; j++) {
      subs.emplace_back(str.substr(i, j));
    }
  }
  return subs;
}
