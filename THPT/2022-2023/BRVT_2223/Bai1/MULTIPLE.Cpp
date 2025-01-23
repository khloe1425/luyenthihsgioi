#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    // Khai báo file input và output
    ifstream inputFile("MULTIPLE.INP");
    ofstream outputFile("MULTIPLE.OUT");

    // Biến lưu số lượng n và hệ số q
    long long n, q;
    inputFile >> n >> q;

    // Tính tổng hạt thóc
    long long total = 0;
    long long current = 1; // Bắt đầu từ 1 hạt thóc

    for (int i = 0; i < n; i++) {
        total += current;
        current *= q; // Mỗi lần nhân với q
    }

    // Xuất ra file kết quả
    outputFile << total % 2023;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
