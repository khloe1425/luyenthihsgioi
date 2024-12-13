#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("CHIAKEO.INP");
    ofstream outputFile("CHIAKEO.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    long long N;
    inputFile >> N; // Đọc số N từ file input

    // Nếu N lẻ, không thể chia
    if (N % 2 != 0) {
        outputFile << -1 << endl; // Ghi -1 vào file output
    } else {
        // Nếu N chẵn, chia đều
        long long x = N / 2;
        long long y = N / 2;
        outputFile << x << " " << y << endl; // Ghi x và y vào file output
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
