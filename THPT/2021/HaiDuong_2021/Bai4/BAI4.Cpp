#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("BAI4.INP");  // Mở file đầu vào
    ofstream outputFile("BAI4.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n;
    string dominoes;
    inputFile >> n >> dominoes;

    string leftImpact(n, '.'), rightImpact(n, '.');

    // Xử lý lật về bên trái ('L')
    char last = '.';
    for (int i = 0; i < n; ++i) {
        if (dominoes[i] == 'L') last = 'L';
        else if (dominoes[i] == 'R') last = '.';
        else if (last == 'L') leftImpact[i] = 'L';
    }

    // Xử lý lật về bên phải ('R')
    last = '.';
    for (int i = n - 1; i >= 0; --i) {
        if (dominoes[i] == 'R') last = 'R';
        else if (dominoes[i] == 'L') last = '.';
        else if (last == 'R') rightImpact[i] = 'R';
    }

    // Đếm số domino không bị ảnh hưởng (đứng yên)
    int stableCount = 0;
    for (int i = 0; i < n; ++i) {
        if (leftImpact[i] == '.' && rightImpact[i] == '.' && dominoes[i] == '.') {
            stableCount++;
        }
    }

    outputFile << stableCount << endl;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
