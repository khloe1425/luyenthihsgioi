#include <iostream>
#include <fstream>

using namespace std;

int main() {
    long long m, n;
    
    // Đọc dữ liệu từ file TROCHOI.INP
    ifstream inputFile("TROCHOI.INP");
    inputFile >> m >> n;
    inputFile.close();
    
    // Tính số que cần thiết
    long long result = 2 * (m * n) + m + n;
    
    // Ghi kết quả ra file TROCHOI.OUT
    ofstream outputFile("TROCHOI.OUT");
    outputFile << result;
    outputFile.close();
    
    return 0;
}
