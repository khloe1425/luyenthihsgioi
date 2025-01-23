#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm tính tích lớn modulo 10^12
unsigned long long factorialLastDigits(int n, int d) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
        result %= static_cast<unsigned long long>(pow(10, d)); // Giữ lại d chữ số cuối
    }
    return result;
}

int main() {
    ifstream inputFile("GIAITHUA.INP");
    ofstream outputFile("GIAITHUA.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N, D;
    while (inputFile >> N >> D) {
        // Tính D chữ số cuối của giai thừa N
        unsigned long long result = factorialLastDigits(N, D);

        // Ghi kết quả vào file
        outputFile << result << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
