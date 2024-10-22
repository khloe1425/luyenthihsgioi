#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

// Hàm kiểm tra số nguyên tố
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm kiểm tra số đối xứng
bool is_palindrome(int n) {
    std::string s = std::to_string(n);
    std::string reversed(s.rbegin(), s.rend());
    return s == reversed;
}

// Hàm đếm số lượng số nguyên tố đối xứng
int count_palindromic_primes(int x) {
    int count = 0;
    for (int num = 11; num < x; ++num) {
        if (is_prime(num) && is_palindrome(num)) {
            count++;
        }
    }
    return count;
}

int main() {
    int x;

    // Đọc giá trị x từ file NTDX.INP
    std::ifstream input_file("NTDX.INP");
    if (input_file.is_open()) {
        input_file >> x;  // Đọc số nguyên dương x
        input_file.close();
    } else {
        std::cerr << "Không thể mở file NTDX.INP" << std::endl;
        return 1;
    }

    // Gọi hàm đếm số lượng số nguyên tố đối xứng
    int result = count_palindromic_primes(x);

    // Ghi kết quả ra file NTDX.OUT
    std::ofstream output_file("NTDX.OUT");
    if (output_file.is_open()) {
        output_file << result << std::endl;  // Ghi số nguyên m vào file
        output_file.close();
    } else {
        std::cerr << "Không thể mở file NTDX.OUT" << std::endl;
        return 1;
    }

    return 0;
}
