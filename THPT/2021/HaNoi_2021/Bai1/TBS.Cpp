#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("TBS.INP");  // Mở file đầu vào
    ofstream outputFile("TBS.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    double A, B, C, D;
    inputFile >> A >> B >> C >> D;

    // Kiểm tra các trường hợp
    if (A == 0 || B == 0 || C == 0 || D == 0) {
        outputFile << 0 << endl; // Tích bằng 0 nếu có bất kỳ số nào bằng 0
    } else {
        int negativeCount = 0;
        if (A < 0) negativeCount++;
        if (B < 0) negativeCount++;
        if (C < 0) negativeCount++;
        if (D < 0) negativeCount++;

        // Tích là số âm nếu số lượng số âm là lẻ
        if (negativeCount % 2 == 1) {
            outputFile << -1 << endl;
        } else {
            outputFile << 1 << endl; // Tích là số dương nếu số lượng số âm là chẵn
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
