#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Mở file input
    ifstream inputFile("BAI02.INP");
    ofstream outputFile("BAI02.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    string str1, str2;
    getline(inputFile, str1);
    getline(inputFile, str2);

    // Gộp hai xâu lại
    string merged = str1 + str2;

    // Tách chữ hoa và chữ thường
    vector<char> upperCase, lowerCase;

    for (char c : merged) {
        if (isalpha(c)) { // Kiểm tra ký tự có phải chữ cái không
            if (isupper(c)) {
                upperCase.push_back(c);
            } else {
                lowerCase.push_back(c);
            }
        }
    }

    // Sắp xếp chữ hoa và chữ thường theo thứ tự giảm dần
    sort(upperCase.begin(), upperCase.end(), greater<char>());
    sort(lowerCase.begin(), lowerCase.end(), greater<char>());

    // Gộp kết quả
    string result = string(upperCase.begin(), upperCase.end()) + string(lowerCase.begin(), lowerCase.end());

    // Ghi kết quả ra file output
    outputFile << result;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
