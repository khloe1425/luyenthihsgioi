#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    // Mở file input để đọc dữ liệu
    ifstream infile("disp.inp");
    ofstream outfile("disp.out");

    long long n;
    infile >> n; // Đọc giá trị n

    long long best_a = 1, best_b = n; // Biến lưu cặp (a, b) tốt nhất ban đầu

    // Duyệt các giá trị a từ 1 đến sqrt(n)
    for (long long a = 1; a * a <= n; ++a) {
        if (n % a == 0) { // Nếu a là ước của n
            long long b = n / a;
            if (a <= b && b - a < best_b - best_a) {
                // Cập nhật nếu tìm được cặp (
