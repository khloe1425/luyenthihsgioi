#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Hàm kiểm tra các điều kiện
bool isValid(int num) {
    string s = to_string(num);
    // Kiểm tra có ít nhất 2 chữ số
    if (s.length() < 2) return false;
    // Kiểm tra tất cả các chữ số giống nhau
    for (char c : s) {
        if (c != s[0]) return false;
    }
    // Kiểm tra chia hết cho 9
    if (num % 9 != 0) return false;
    return true;
}

int main() {
    ifstream inputFile("BAI2.INP");
    ofstream outputFile("BAI2.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở tệp!" << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    int count = 0;
    for (int i = 10; i < N; ++i) { // Duyệt các số từ 10 đến N-1
        if (isValid(i)) {
            ++count;
        }
    }

    outputFile << count << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
