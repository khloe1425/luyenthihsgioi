#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm tính toán số ký tự cần thay đổi
int calculateDifferences(const string &S, const string &prefix, int m, int r) {
    int differences = 0;
    for (int i = 0; i < m; ++i) {
        if (S[i] != prefix[i]) {
            ++differences;
            if (differences > r) return m; // Ngừng kiểm tra nếu vượt quá r
        }
    }
    return differences;
}

int main() {
    ifstream inputFile("COMSTR.INP");
    ofstream outputFile("COMSTR.OUT");

    // Đọc dữ liệu đầu vào
    int m, m1, m2, r;
    string S;
    inputFile >> m >> m1 >> m2 >> r;
    inputFile >> S;

    // Khởi tạo chuỗi F1 và F2
    string F1 = S.substr(0, m1); // Lấy m1 ký tự đầu tiên
    string F2 = S.substr(m1, m2); // Lấy m2 ký tự tiếp theo

    // Xây dựng các tiền tố của Fk
    vector<string> prefixes = {F1, F2};
    while (prefixes.back().size() < m) {
        string newPrefix = prefixes[prefixes.size() - 1] + prefixes[prefixes.size() - 2];
        prefixes.push_back(newPrefix);
    }

    // So sánh với các tiền tố để tìm số thay đổi tối thiểu
    int minChanges = m; // Giá trị lớn ban đầu
    for (const auto &prefix : prefixes) {
        int changes = calculateDifferences(S, prefix, m, r);
        minChanges = min(minChanges, changes);
    }

    // Ghi kết quả ra file
    outputFile << minChanges << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
