inline bool is_alpha(const char ch) {
  return std::isalpha(static_cast<unsigned char>(ch));
}

inline char to_lower(const char ch) {
  return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

inline bool is_upper(const char ch) {
  return std::isupper(static_cast<unsigned char>(ch));
}

inline char to_upper(const char ch) {
  return static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
}