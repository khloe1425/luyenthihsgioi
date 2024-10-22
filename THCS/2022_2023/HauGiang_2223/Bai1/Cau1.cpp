#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

int main() {
    // Đọc dữ liệu từ tệp xau.inp
    std::ifstream inputFile("xau.inp");
    std::string s;
    inputFile >> s;
    inputFile.close();

    // Tạo một tập hợp chứa tất cả các ký tự từ A đến Z
    std::set<char> allCharacters;
    for (char c = 'A'; c <= 'Z'; ++c) {
        allCharacters.insert(c);
    }

    // Tạo một tập hợp chứa các ký tự đã xuất hiện trong xâu S
    std::set<char> presentCharacters(s.begin(), s.end());

    // Tìm các ký tự còn thiếu
    std::set<char> missingCharacters;
    for (char c : allCharacters) {
        if (presentCharacters.find(c) == presentCharacters.end()) {
            missingCharacters.insert(c);
        }
    }

    // Ghi ra tệp xau.out các ký tự còn thiếu
    std::ofstream outputFile("xau.out");
    for (char c : missingCharacters) {
        outputFile << c;
    }
    outputFile.close();

    return 0;
}
