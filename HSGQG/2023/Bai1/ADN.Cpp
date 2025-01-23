#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra độ phức tạp của một chuỗi
int calculateDiversity(const string &s) {
    int n = s.size();
    set<string> uniqueSubstrings;

    // Duyệt qua tất cả các đoạn con
    for (int i = 0; i < n; ++i) {
        set<char> charSet; // Lưu các ký tự khác nhau trong đoạn con
        string currentSubstring = "";

        for (int j = i; j < n; ++j) {
            charSet.insert(s[j]);
            currentSubstring += s[j];

            // Nếu đoạn con có ít nhất 2 ký tự khác nhau, thêm vào tập
            if (charSet.size() > 1) {
                uniqueSubstrings.insert(currentSubstring);
            }
        }
    }

    return uniqueSubstrings.size();
}

// Hàm đệ quy thay thế tất cả '?' và tìm độ đa dạng nhỏ nhất
void findMinimumDiversity(string &s, int pos, int &minDiversity) {
    if (pos == s.size()) {
        // Tính độ đa dạng của chuỗi sau khi đã thay thế
        minDiversity = min(minDiversity, calculateDiversity(s));
        return;
    }

    // Nếu ký tự hiện tại là '?', thử thay thế bằng A, T, G, X
    if (s[pos] == '?') {
        for (char c : {'A', 'T', 'G', 'X'}) {
            s[pos] = c;
            findMinimumDiversity(s, pos + 1, minDiversity);
            s[pos] = '?'; // Hoàn nguyên
        }
    } else {
        // Nếu không phải '?', tiếp tục đệ quy
        findMinimumDiversity(s, pos + 1, minDiversity);
    }
}

int main() {
    // Đọc dữ liệu từ file ADN.INP
    ifstream inputFile("ADN.INP");
    ofstream outputFile("ADN.OUT");
    string s;
    inputFile >> s;

    // Biến lưu độ đa dạng nhỏ nhất
    int minDiversity = INT_MAX;

    // Gọi hàm đệ quy để tìm độ đa dạng nhỏ nhất
    findMinimumDiversity(s, 0, minDiversity);

    // Ghi kết quả ra file ADN.OUT
    outputFile << minDiversity << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
