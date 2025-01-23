#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("BAI1.INP");  // Mở file đầu vào
    ofstream outputFile("BAI1.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    long long A; // Số m3 nước sử dụng
    inputFile >> A;

    long long total = 0;

    if (A <= 5) {
        total = A * 8000;
    } else if (A <= 10) {
        total = 5 * 8000 + (A - 5) * 10000;
    } else if (A <= 15) {
        total = 5 * 8000 + 5 * 10000 + (A - 10) * 14000;
    } else if (A <= 20) {
        total = 5 * 8000 + 5 * 10000 + 5 * 14000 + (A - 15) * 20000;
    } else {
        total = 5 * 8000 + 5 * 10000 + 5 * 14000 + 5 * 20000 + (A - 20) * 30000;
    }

    // Thêm VAT 10%
    total = total + total / 10;

    outputFile << total << endl; // Ghi kết quả vào file

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
