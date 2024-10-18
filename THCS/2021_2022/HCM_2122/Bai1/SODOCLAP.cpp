#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;

// Hàm kiểm tra một số có phải số độc lập hay không
bool isIndependent(int n) {
    set<char> digits;
    string s = to_string(n);
    for (char c : s) {
        if (digits.find(c) != digits.end()) return false;
        digits.insert(c);
    }
    return true;
}

int main() {
    // Đọc dữ liệu từ file SODOCLAP.INP
    ifstream inputFile("SODOCLAP.INP");
    ofstream outputFile("SODOCLAP.OUT");

    int X;
    inputFile >> X;

    // Tìm số độc lập nhỏ nhất lớn hơn X
    int result = X + 1;
    while (!isIndependent(result)) {
        result++;
    }

    // Ghi kết quả ra file SODOCLAP.OUT
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
