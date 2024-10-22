#include <iostream>
#include <fstream>
#include <cmath>

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::string x;

    // Đọc giá trị x từ file TONGHV.INP
    std::ifstream input_file("TONGHV.INP");
    if (input_file.is_open()) {
        input_file >> x;  // Đọc số nguyên dương x
        input_file.close();
    } else {
        std::cerr << "Không thể mở file TONGHV.INP" << std::endl;
        return 1;
    }

    int n = x.size();
    long long sum_digits = 0;

    // Tính tổng các chữ số
    for (char c : x) {
        sum_digits += c - '0';  // Chuyển từ ký tự sang số
    }

    // Tính n!
    long long n_factorial = factorial(n);

    // Tính tổng giá trị của các vị trí
    long long positional_sum = 0;
    long long power_of_10 = 1;

    // Tính tổng giá trị các vị trí
    for (int i = 0; i < n; ++i) {
        positional_sum += power_of_10; // 1 + 10 + 100 + ...
        power_of_10 *= 10;
    }

    // Tổng hoán vị
    long long total_sum = (n_factorial * sum_digits * positional_sum);

    // Ghi kết quả ra file TONGHV.OUT
    std::ofstream output_file("TONGHV.OUT");
    if (output_file.is_open()) {
        output_file << total_sum << std::endl;  // Ghi số nguyên m vào file
        output_file.close();
    } else {
        std::cerr << "Không thể mở file TONGHV.OUT" << std::endl;
        return 1;
    }

    return 0;
}
