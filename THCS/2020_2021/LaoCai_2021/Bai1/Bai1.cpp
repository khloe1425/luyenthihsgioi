#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("BAI1.INP");
    ofstream outputFile("BAI1.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    // Tính số lượng bắt tay
    long long result = (long long)n * (n - 1) / 2;

    // Ghi kết quả ra file
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
