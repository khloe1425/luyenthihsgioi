#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm> // std::transform
using namespace std;

// Hàm chuyển chuỗi thành chữ thường
string toLowerCase(const string &str) {
    string result = str;
    transform(str.begin(), str.end(), back_inserter(result), ::tolower);
    return result;
}

// Hàm kiểm tra xem một từ có khớp với từ đại diện P không
bool isMatch(const string &word, const string &pattern) {
    if (word.length() != pattern.length()) return false; // Kiểm tra độ dài
    for (size_t i = 0; i < word.length(); ++i) {
        if (pattern[i] != '?' && word[i] != pattern[i]) {
            return false; // Nếu ký tự không khớp
        }
    }
    return true;
}

int main() {
    // Mở file input và output
    ifstream inputFile("DAIDIEN.INP");
    ofstream outputFile("DAIDIEN.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở tệp!" << endl;
        return 1;
    }

    string S, P;
    getline(inputFile, S); // Đọc xâu S
    getline(inputFile, P); // Đọc xâu P

    // Chuyển cả S và P thành chữ thường
    S = toLowerCase(S);
    P = toLowerCase(P);

    // Tách xâu S thành danh sách các từ
    stringstream ss(S);
    string word;
    int count = 0;
    while (ss >> word) {
        if (isMatch(word, P)) { // Kiểm tra từng từ với từ đại diện
            count++;
        }
    }

    // Ghi kết quả vào tệp
    outputFile << count << endl;

    // Đóng tệp
    inputFile.close();
    outputFile.close();

    return 0;
}
