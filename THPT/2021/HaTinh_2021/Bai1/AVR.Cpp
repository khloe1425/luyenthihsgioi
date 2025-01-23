#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile("AVR.INP");  // Mở file đầu vào
    ofstream outputFile("AVR.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    vector<long long> b(n), a(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> b[i];
    }

    // Xây dựng dãy a từ b
    a[0] = b[0]; // a1 = b1
    for (int i = 1; i < n; ++i) {
        a[i] = b[i] * (i + 1) - (b[i - 1] * i);
    }

    // Ghi kết quả ra file
    for (int i = 0; i < n; ++i) {
        outputFile << a[i] << " ";
    }
    outputFile << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
