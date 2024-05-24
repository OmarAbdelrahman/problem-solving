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

inline bool is_vowel(const char ch) {
  return ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' ||
         ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' ||
         ch == 'u' || ch == 'U';
}

inline bool is_consonant(const char ch) {
  return !is_vowel(ch);
}