#include "iostream"
#include "unordered_map"
#include "vector"
#include "tuple"
#include "algorithm"

class Barcodes {
public:
  std::string solveOne(const std::vector<int>& sensors) {
    const int n = sensors.size();
    // basic valid barcode with one encoded character should contain 29 bits
    // and each new character adds 6 bit (5 bits for code and 1 bit for separator) to the barcode
    if (n % 6 != 5) {
      return "bad code";
    }
    if ((n + 1) / 6 < 5) { // no codes, just 'START-C-K-STOP'
      return "bad code";
    }
    const double width_threshold = get_width_threshold(sensors);
    int min_value, max_value;
    std::tie(min_value, max_value) = get_width_value(sensors, width_threshold);
    if (max_value * 95 > min_value * 105) {
      return "bad code";
    }
    std::vector<std::string> barcodes = build_barcodes(sensors, width_threshold);
    if (barcodes.empty()) {
      return "bad code";
    }
    if (barcodes.front() == REV_START) {
      std::reverse(barcodes.begin(), barcodes.end());
      for (std::string& barcode : barcodes) {
        std::reverse(barcode.begin(), barcode.end());
      }
    }
    if (barcodes.front() != START || barcodes.back() != STOP) {
      return "bad code";
    }
    for (int i = 0; i < barcodes.size(); i++) {
      if (code.find(barcodes[i]) == code.end()) {
        return "bad code";
      }
      if (i > 0 && i < barcodes.size() - 1 && barcodes[i] == START) {
        return "bad code";
      }
    }
    const int C = calculate_C(barcodes);
    const int K = calculate_K(barcodes);
    const int m = barcodes.size();
    if (code[barcodes[m - 3]] != C) {
      return "bad C";
    }
    if (code[barcodes[m - 2]] != K) {
      return "bad K";
    }
    std::string result;
    for (int i = 1; i < m - 3; i++) {
      const int value = code[barcodes[i]];
      if (value == 10) result += "-"; else result += std::to_string(value);
    }
    return result; 
  }

  void solve() {
    for (int _ = 1, n; in >> n && n; _++) {
      out << "Case " << _ << ": ";
      std::vector<int> sensors(n);
      for (int& sensor : sensors) in >> sensor;
      out << solveOne(sensors) << '\n';
    }
  }

  Barcodes(std::istream& in, std::ostream& out): in(in), out(out) {
    code["00001"] = 0, code["10001"] = 1;
    code["01001"] = 2, code["11000"] = 3;
    code["00101"] = 4, code["10100"] = 5;
    code["01100"] = 6, code["00011"] = 7;
    code["10010"] = 8, code["10000"] = 9;
    code["00100"] = 10;
    code["00110"] = -1;
  }

private:
  int calculate_C(const std::vector<std::string>& barcodes) {
    const int n = barcodes.size() - 3; // exclude C-K-STOP
    int C = 0;
    for (int i = 1; i < n; i++) {
      C = (C + ((((n - 1) - i) % 10) + 1) * code[barcodes[i]]) % 11;
    }
    return C;
  }

  int calculate_K(const std::vector<std::string>& barcodes) {
    const int n = barcodes.size() - 2; // exclude K-STOP
    int K = 0;
    for (int i = 1; i < n; i++) {
      K = (K + ((((n - 2) - i + 1) % 9) + 1) * code[barcodes[i]]) % 11;
    }
    return K;
  }

  std::vector<std::string> build_barcodes(const std::vector<int>& sensors, const double& width_threshold) {
    const int n = sensors.size();
    std::vector<std::string> barcodes;
    for (int i = 0; i < n; i += 6) {
      std::string barcode;
      for (int j = i; j < i + 5; j++) {
        barcode += sensors[j] < width_threshold ? "0" : "1";
      }
      if (i + 5 < n && sensors[i + 5] >= width_threshold) { // if no separator, then "bad code"
        return {};
      }
      barcodes.emplace_back(barcode);
    }
    return barcodes;
  }

  double get_width_threshold(const std::vector<int>& sensors) {
    int min_value = *std::min_element(sensors.begin(), sensors.end());
    int max_value = *std::max_element(sensors.begin(), sensors.end());
    return (min_value + max_value) / 2.0;
  }

  std::tuple<int, int> get_width_value(const std::vector<int>& sensors, const double& width_threshold) {
    int min_value = 1e9, max_value = -1;
    for (const int& sensor : sensors) {
      int width_value = sensor;
      if (sensor < width_threshold) {
        width_value *= 2;
      }
      min_value = std::min(min_value, width_value);
      max_value = std::max(max_value, width_value);
    }
    return {min_value, max_value};
  }

  std::istream& in;
  std::ostream& out;

  std::unordered_map<std::string, int> code;

  const std::string START = "00110";
  const std::string REV_START = "01100";
  const std::string STOP = "00110";
};
