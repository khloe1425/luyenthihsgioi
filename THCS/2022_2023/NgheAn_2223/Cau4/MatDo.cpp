#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;

int max_high_density_length(const string& s) {
    int n = s.size();
    int max_length = 0;

    // Duyệt từng vị trí trong chuỗi
    for (int i = 0; i < n; ++i) {
        unordered_map<char, int> count;  // Đếm số lần xuất hiện của các ký tự
        for (int j = i; j < n; ++j) {
            char char_j = s[j];
            count[char_j]++;

            // Tính số lần xuất hiện nhiều nhất
            int max_count = 0;
            for (const auto& pair : count) {
                max_count = max(max_count, pair.second);
            }
            
            int total_count = j - i + 1;
            int other_count = total_count - max_count;

            // Kiểm tra điều kiện mật độ xuất hiện cao
            if (max_count > other_count) {
                max_length = max(max_length, total_count);
            }
        }
    }

    return max_length;
}

int main() {
    ifstream input("MatDo.Inp");
    ofstream output("MatDo.Out");
    string s;

    // Đọc dữ liệu từ tệp MatDo.INP
    getline(input, s);

    // Tính độ dài chuỗi con có mật độ xuất hiện cao
    int result = max_high_density_length(s);

    // Ghi kết quả vào tệp MatDo.OUT
    output << result << endl;

    return 0;
}
