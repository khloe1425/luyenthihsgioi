#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Hàm kiểm tra một dãy ký tự có thỏa mãn quy luật bàn phím không
bool isValidKeyboardSequence(const string& s) {
    int n = s.size();
    int expectedCount = 1; // Số lượng ký tự cần gõ theo quy luật

    for (int i = 0; i < n;) {
        int count = 1;

        // Đếm số lần lặp lại liên tiếp của ký tự hiện tại
        while (i + 1 < n && s[i] == s[i + 1]) {
            count++;
            i++;
        }

        // Kiểm tra nếu số lần lặp không đúng với quy luật
        if (count != expectedCount) {
            return false;
        }

        // Chuyển sang ký tự tiếp theo và tăng số lần kỳ vọng
        i++;
        expectedCount++;
    }

    return true;
}

int main() {
    ifstream inputFile("KEYBOARD.INP");
    ofstream outputFile("KEYBOARD.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int T; // Số lượng dãy ký tự
    inputFile >> T;
    inputFile.ignore(); // Bỏ qua ký tự xuống dòng sau số T

    int validCount = 0; // Đếm số dãy thỏa mãn quy luật

    while (T--) {
        string s;
        getline(inputFile, s); // Đọc từng dãy ký tự

        if (isValidKeyboardSequence(s)) {
            validCount++;
        }
    }

    // Ghi kết quả ra file
    outputFile << validCount << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
