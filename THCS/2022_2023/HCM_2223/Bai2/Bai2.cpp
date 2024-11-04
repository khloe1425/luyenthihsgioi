#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Hàm đệ quy để tạo ra tất cả các chuỗi
void generateStrings(int idx, const string &base, vector<string> &results, const vector<vector<char>> &replacements, string current) {
    if (idx == base.size()) {
        results.push_back(current); // Thêm chuỗi hiện tại vào kết quả
        return;
    }
    
    if (base[idx] == '#') {
        for (char ch : replacements[idx]) {
            generateStrings(idx + 1, base, results, replacements, current + ch); // Thay thế #
        }
    } else {
        generateStrings(idx + 1, base, results, replacements, current + base[idx]); // Giữ nguyên ký tự
    }
}

int main() {
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    cin.ignore(); // Đọc dòng mới sau khi đọc các số nguyên

    string base_string;
    getline(cin, base_string); // Đọc chuỗi n ký tự

    vector<vector<char>> replacements(m); // Lưu trữ các ký tự thay thế cho mỗi #
    
    for (int i = 0; i < m; ++i) {
        string replacement;
        getline(cin, replacement);
        replacements[i] = vector<char>(replacement.begin(), replacement.end());
        sort(replacements[i].begin(), replacements[i].end()); // Sắp xếp ký tự thay thế
    }

    vector<string> results; // Danh sách để lưu trữ các chuỗi kết quả
    generateStrings(0, base_string, results, replacements, ""); // Gọi hàm đệ quy

    // Sắp xếp danh sách các chuỗi theo thứ tự từ điển
    sort(results.begin(), results.end());

    // In ra tối đa 8 chuỗi
    for (int i = 0; i < min(8, (int)results.size()); ++i) {
        cout << i + 1 << ". " << results[i] << endl; // In ra các chuỗi theo thứ tự
    }

    return 0;
}
