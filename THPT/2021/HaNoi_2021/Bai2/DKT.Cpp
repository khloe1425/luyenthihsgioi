#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("DKT.INP");  // Mở file đầu vào
    ofstream outputFile("DKT.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    long long N;
    inputFile >> N;

    // Tính tổng bước nhảy modulo 26
    long long position = (N * (N + 1) / 2) % 26;

    // Chuyển vị trí sang kí tự
    char result = 'A' + position;

    // Ghi kết quả
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
