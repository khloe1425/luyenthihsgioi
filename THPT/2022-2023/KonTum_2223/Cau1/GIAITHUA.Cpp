#include <iostream>
#include <fstream>
using namespace std;

// Hàm tính giai thừa
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    // Đọc dữ liệu từ file GIAITHUA.INP
    ifstream inputFile("GIAITHUA.INP");
    ofstream outputFile("GIAITHUA.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    // Tính giai thừa của N
    unsigned long long result = factorial(N);

    // Ghi kết quả ra file GIAITHUA.OUT
    outputFile << result;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
