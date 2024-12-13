#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("KYTUDT.INP");
    ofstream outputFile("KYTUDT.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    int k;
    string s;

    // Đọc dữ liệu từ file
    inputFile >> k;
    inputFile.ignore(); // Bỏ qua ký tự xuống dòng
    getline(inputFile, s);

    unordered_map<char, int> freq;
    for (size_t i = 0; i < s.size(); i++) {
        freq[s[i]]++;
        if (freq[s[i]] == k) {
            // Ghi vị trí đầu tiên của ký tự thỏa mãn
            outputFile << (i + 1) << endl;
            inputFile.close();
            outputFile.close();
            return 0;
        }
    }

    // Nếu không có ký tự nào thỏa mãn
    outputFile << -1 << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
