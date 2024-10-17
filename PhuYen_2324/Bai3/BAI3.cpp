#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm tính tổng bình phương các chữ số
int sum_of_squares_of_digits(const string& num) {
    int sum = 0;
    for (char digit : num) {
        sum += (digit - '0') * (digit - '0');
    }
    return sum;
}

int main() {
    ifstream infile("BAI3.INP");
    ofstream outfile("BAI3.OUT");

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int n;
    infile >> n; // Đọc số n
    vector<string> results;

    // Đọc từng số ai
    for (int i = 0; i < n; ++i) {
        string a;
        infile >> a; // Đọc số ai
        int sum_squares = sum_of_squares_of_digits(a); // Tính tổng bình phương

        // Chỉ chuyển đổi tổng bình phương thành số nguyên nếu số có ít hơn 10 chữ số
        if (sum_squares < 100000) { 
            if (is_prime(sum_squares)) { // Kiểm tra số đẹp
                results.push_back(a + " " + to_string(sum_squares)); // Lưu kết quả
            }
        } else {
            // Tính tổng bình phương cho trường hợp số lớn hơn 10 chữ số
            long long sum_squares_large = 0;
            for (char digit : a) {
                sum_squares_large += (digit - '0') * (digit - '0');
            }
            if (is_prime(sum_squares_large)) { // Kiểm tra số đẹp
                results.push_back(a + " " + to_string(sum_squares_large)); // Lưu kết quả
            }
        }
    }

    // Ghi kết quả vào file
    if (results.empty()) {
        outfile << "0" << endl; // Ghi 0 nếu không có số đẹp
    } else {
        for (const string& result : results) {
            outfile << result << endl; // Ghi các số đẹp
        }
    }

    infile.close();
    outfile.close();
    return 0;
}
