#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("BANH.INP");
    ofstream outputFile("BANH.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int L, N; // L: số hộp bánh lớn, N: số hộp bánh nhỏ
    inputFile >> L >> N;

    // Tính tổng số bánh
    int totalCakes = L * 8 + N * 3;

    // Tính số bánh còn dư sau khi chia cho 28 học sinh
    int remainingCakes = totalCakes % 28;

    // Ghi kết quả ra file
    outputFile << remainingCakes << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
