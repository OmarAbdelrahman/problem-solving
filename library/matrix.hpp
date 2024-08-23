template<class T>
struct matrix {

  static matrix<T> Identity(const int n) {
    matrix<T> identity(n);
    for (int i = 0; i < n; i++) {
      identity[i][i] = 1;
    }
    return identity;
  }

  matrix(const int _rows, const int _cols = -1) {
    init(_rows, _cols);
  }

  template<class U>
  matrix(const int _rows, const int _cols, const U value) {
    init(_rows, _cols, value);
  }

  matrix(const std::vector<std::string>& _values) {
    init(_values);
  }

  template<class U>
  explicit matrix(const std::vector<std::vector<U>>& _values) {
    init(_values);
  }

  void init(const int _rows, const int _cols = -1) {
    rows = _rows;
    cols = _cols < 0 ? _rows : _cols;
    values.assign(rows, std::vector<T>(cols, 0));
  }

  template<class U>
  void init(const int _rows, const int _cols, const U value) {
    rows = _rows;
    cols = _cols;
    values.assign(rows, std::vector<T>(cols, value));
  }

  void init(const std::vector<std::string>& _values) {
    const int _rows = _values.size();
    const int _cols = _values[0].size();
    values = std::vector<std::vector<char>>(_rows);
    for (int i = 0; i < _rows; i++) {
      values[i] = std::vector<char>(_values[i].begin(), _values[i].end());
    }
    rows = _rows;
    cols = _cols;
  }

  template<class U>
  void init(const std::vector<std::vector<U>>& _values) {
    values = _values;
    rows = values.size();
    cols = values[0].size();
  }

  template<class U>
  inline void fill(const U value) {
    for (auto& row : values) {
      std::fill(row.begin(), row.end(), value);
    }
  }

  template<class F>
  inline void for_each(F&& f) {
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        f(values[i][j]);
  }
  template<class F>
  inline void for_each_with_indices(F&& f) {
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        f(i, j, values[i][j]);
  }

  inline int rows_count() const { return rows; }
  inline int cols_count() const { return cols; }
  inline bool is_square() const { return rows == cols; }

  inline bool contains_pos(const int i, const int j) const {
    assert(!values.empty());
    return 0 <= i && i < rows && 0 <= j && j < cols;
  }
  inline bool contains_pos(const std::pair<int, int>& p) const {
    return contains_pos(p.first, p.second);
  }
  inline bool contains_pos(const std::tuple<int, int>& t) const {
    return contains_pos(std::get<0>(t), std::get<1>(t));
  }

  void transpose() {
    if (is_square()) {
      for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
          std::swap(values[i][j], values[j][i]);
        }
      }
    } else {
      matrix<T> t(cols, rows);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          t[j][i] = values[i][j];
        }
      }
      *this = t;
    }
  }

  inline void rotate(const bool clockwise = true) {
    if (clockwise) rotate_90_clockwise(); else rotate_90_anti_clockwise();
  }

  void reflect_vertically() {
    const int mid = cols / 2;
    for (int i = 0; i < mid; i++) {
      for (int j = 0; j < rows; j++) {
        std::swap(values[j][i], values[j][rows - i - 1]);
      }
    }
  }

  void reflect_horizontally() {
    std::reverse(values.begin(), values.end());
  }

  std::pair<int, int> find_first_of(const T value) const {
    assert(!values.empty());
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (values[i][j] == value) {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }

  template<class U> matrix<T>& operator+=(const U u) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        values[i][j] += u;
      }
    }
    return *this;
  }
  template<class U> matrix<T>& operator-=(const U u) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        values[i][j] -= u;
      }
    }
    return *this;
  }
  template<class U> matrix<T>& operator*=(const U u) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        values[i][j] *= u;
      }
    }
    return *this;
  }
  template<class U> matrix<T>& operator/=(const U u) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        values[i][j] /= u;
      }
    }
    return *this;
  }
  template<class U> matrix<T> operator+(const U u) const { return matrix<T>(*this) += u; }
  template<class U> matrix<T> operator-(const U u) const { return matrix<T>(*this) -= u; }
  template<class U> matrix<T> operator*(const U u) const { return matrix<T>(*this) *= u; }
  template<class U> matrix<T> operator/(const U u) const { return matrix<T>(*this) /= u; }

  template<class U>
  matrix<T>& operator+=(const matrix<U>& other) {
    assert(rows == other.rows && cols == other.cols);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        values[i][j] += other[i][j];
      }
    }
    return *this;
  }
  template<class U>
  matrix<T>& operator-=(const matrix<U>& other) const {
    assert(rows == other.rows && cols == other.cols);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        values[i][j] -= other[i][j];
      }
    }
    return *this;
  }
  template<class U>
  matrix<T>& operator/=(const matrix<U>& other) const {
    assert(rows == other.rows && cols == other.cols);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        values[i][j] /= other[i][j];
      }
    }
    return *this;
  }

  template<class U> matrix<T> operator+(const matrix<U>& other) const { return matrix<T>(*this) += other; }
  template<class U> matrix<T> operator-(const matrix<U>& other) const { return matrix<T>(*this) -= other; }
  template<class U> matrix<T> operator/(const matrix<U>& other) const { return matrix<T>(*this) /= other; }

  template<class U>
  matrix<T> operator*(const matrix<U>& other) const {
    assert(cols == other.cols);
    matrix<T> product(rows, other.cols);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (values[i][j] != 0) {
          for (int k = 0; k < other.cols; k++) {
            product[i][k] += values[i][j] * other[j][k];
          }
        }
      }
    }
    return product;
  }
  template<class U>
  matrix<T>& operator*=(const matrix<U>& other) {
    return *this = *this * other;
  }
  template<class U>
  std::vector<T> operator*(const std::vector<U>& column) const {
    assert(cols == int(column.size()));
    std::vector<T> product(rows);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        product[i] += values[i][j] * column[j];
      }
    }
    return product;
  }

  matrix<T> power(int p) const {
    assert(p >= 0);
    assert(is_square());
    matrix<T> mat = *this;
    matrix<T> result = Identity(rows);
    while (p > 0) {
      if (p & 1) result *= mat;
      p >>= 1;
      if (p > 0) mat *= mat;
    }
    return result;
  }

  std::vector<T>& operator[](const int at) { return values[at]; }
  const std::vector<T>& operator[](const int at) const { return values[at]; }

  T& operator[](const std::pair<int, int>& at) { return values[at.first][at.second]; }
  const T& operator[](const std::pair<int, int>& at) const { return values[at.first][at.second]; }
  T& operator[](const std::tuple<int, int>& at) { return values[std::get<0>(at)][std::get<1>(at)]; }
  const T& operator[](const std::tuple<int, int>& at) const { return values[std::get<0>(at)][std::get<1>(at)]; }

  template<class U>
  inline bool operator==(const matrix<U>& other) const {
    return values == other.values;
  }

  inline void print(std::ostream& out) const {
    if (std::is_same<T, char>::value) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          out << values[i][j];
        }
        out << '\n';
      }
    } else {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          out << values[i][j] << " \n"[j == cols - 1];
        }
      }
    }
  }

  template<class U>
  friend std::istream& operator>>(std::istream& in, matrix<U>& mat) {
    assert(!mat.values.empty());
    if (std::is_same<T, char>::value) {
      for (int i = 0; i < mat.rows; i++) {
        std::string chars;
        in >> chars;
        mat[i] = std::vector<char>(chars.begin(), chars.end());
      }
    } else {
      for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
          in >> mat[i][j];
        }
      }
    }
    return in;
  }

private:
  void rotate_90_clockwise() {
    transpose();
    const int mid = cols / 2;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < mid; j++) {
        std::swap(values[i][j], values[i][cols - j - 1]);
      }
    }
  }

  void rotate_90_anti_clockwise() {
    transpose();
    const int mid = rows / 2;
    for (int i = 0; i < mid; i++) {
      std::swap(values[i], values[rows - i - 1]);
    }
  }

private:
  std::vector<std::vector<T>> values;
  int rows, cols;
};
