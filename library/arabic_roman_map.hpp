struct arabic_roman_map {

  arabic_roman_map() {
    m_arabic[""] = 0;
    m_roman[1] = "I", m_roman[5] = "V";
    m_arabic[m_roman[1]] = 1, m_arabic[m_roman[5]] = 5;
    m_roman[10] = "X", m_roman[50] = "L";
    m_arabic[m_roman[10]] = 10, m_arabic[m_roman[50]] = 50;
    m_roman[100] = "C", m_roman[500] = "D";
    m_arabic[m_roman[100]] = 100, m_arabic[m_roman[500]] = 500;
    m_roman[1000] = "M", m_arabic[m_roman[1000]] = 1000;
    for (int i = 2; i <= 3; ++i) {
      m_roman[i] = m_roman[i - 1] + "I";
      m_arabic[m_roman[i]] = i;
      m_roman[i * 10] = m_roman[(i - 1) * 10] + "X";
      m_arabic[m_roman[i * 10]] = i * 10;
      m_roman[i * 100] = m_roman[(i - 1) * 100] + "C";
      m_arabic[m_roman[i * 100]] = i * 100;
      m_roman[i * 1000] = m_roman[(i - 1) * 1000] + "M";
      m_arabic[m_roman[i * 1000]] = i * 1000;
    }
    for (int i = 0; i < 3; ++i) {
      int v = (int)std::pow(10.0, i);
      m_roman[4 * v] = m_roman[v] + m_roman[5 * v];
      m_arabic[m_roman[4 * v]] = 4 * v;
      m_roman[9 * v] = m_roman[v] + m_roman[v * 10];
      m_arabic[m_roman[9 * v]] = 9 * v;
      for (int j = 6; j <= 8; ++j) {
        m_roman[j * v] = m_roman[5 * v] + m_roman[(j - 5) * v];
        m_arabic[m_roman[j * v]] = j * v;
      }
    }
    for (int i = 10; i < 100; i += 10) {
      for (int j = 1; j < 10; ++j) {
        m_roman[i + j] = m_roman[i] + m_roman[j];
        m_arabic[m_roman[i + j]] = i + j;
      }
    }
    for (int i = 100; i < 1000; i += 100) {
      for (int j = 1; j < 100; ++j) {
        m_roman[i + j] = m_roman[i] + m_roman[j];
        m_arabic[m_roman[i + j]] = i + j;
      }
    }
    for (int i = 1000; i <= 4000; i += 1000) {
      for (int j = 1; j <= 1000; ++j) {
        m_roman[i + j] = m_roman[i] + m_roman[j];
        m_arabic[m_roman[i + j]] = i + j;
      }
    }
  }

  const int& operator[](const std::string& roman) const { return m_arabic.at(roman); }
  int& operator[](const std::string& roman) { return m_arabic[roman]; }
  const std::string& operator[](const int arabic) const { return m_roman.at(arabic); }
  std::string& operator[](const int arabic) { return m_roman[arabic]; }

  inline bool roman_exists(const std::string& roman) const { return m_arabic.find(roman) != m_arabic.end(); }
  inline bool arabic_exists(const int arabic) const { return m_roman.find(arabic) != m_roman.end(); }

private:
  std::unordered_map<int, std::string> m_roman;
  std::unordered_map<std::string, int> m_arabic;

  const std::string numerals = "IVXLCDM";
};
