#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

int findFirstUnique(const string& s) {
    unordered_map<char, int> count; // Đếm số lần xuất hiện của từng ký tự
    unordered_map<char, int> firstPos; // Lưu vị trí xuất hiện đầu tiên của từng ký tự

    // Duyệt qua chuỗi để đếm và lưu vị trí xuất hiện
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        count[c]++;
        if (firstPos.find(c) == firstPos.end()) {
            firstPos[c] = i + 1; // Vị trí bắt đầu từ 1
        }
    }

    // Tìm ký tự xuất hiện duy nhất với vị trí đầu tiên nhỏ nhất
    int minPos = INT_MAX;
    for (auto& pair : count) {
        if (pair.second == 1) {
            minPos = min(minPos, firstPos[pair.first]);
        }
    }

    return (minPos == INT_MAX) ? -1 : minPos;
}

int main() {
    ifstream inputFile("BAI3.INP");  // Mở file đầu vào
    ofstream outputFile("BAI3.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int T;
    inputFile >> T;

    string S;
    getline(inputFile, S); // Đọc dòng còn sót sau số T

    for (int t = 0; t < T; t++) {
        getline(inputFile, S); // Đọc từng chuỗi S
        int result = findFirstUnique(S);
        outputFile << result << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
