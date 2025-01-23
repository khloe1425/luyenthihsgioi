#include <iostream>
#include <fstream>
#include <set>
using namespace std;

// Kiểm tra một chữ số có phải là số nguyên tố không
bool isPrime(int digit) {
    return digit == 2 || digit == 3 || digit == 5 || digit == 7;
}

int main() {
    ifstream inputFile("BAI2.INP");  // Mở file đầu vào
    ofstream outputFile("BAI2.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    string S;
    inputFile >> S;

    set<int> seen; // Tập hợp các chữ số nguyên tố đã gặp
    bool found = false;

    for (char c : S) {
        int digit = c - '0';
        if (isPrime(digit) && seen.find(digit) == seen.end()) {
            // Nếu chữ số là số nguyên tố và chưa xuất hiện trước đó
            if (found) {
                outputFile << " ";
            }
            outputFile << digit;
            seen.insert(digit);
            found = true;
        }
    }

    if (!found) {
        // Nếu không tìm thấy chữ số nguyên tố nào
        outputFile << 0;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
