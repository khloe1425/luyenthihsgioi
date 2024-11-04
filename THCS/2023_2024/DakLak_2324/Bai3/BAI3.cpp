#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

pair<size_t, size_t> longest_unique_substring(const string& s) {
    unordered_map<char, size_t> char_index; // Lưu trữ vị trí của mỗi ký tự
    size_t start = 0; // Chỉ số bắt đầu của đoạn con
    size_t max_length = 0; // Chiều dài đoạn con lớn nhất
    size_t max_start_index = 0; // Chỉ số bắt đầu của đoạn con lớn nhất

    for (size_t end = 0; end < s.length(); ++end) {
        // Nếu ký tự đã xuất hiện trong đoạn con hiện tại
        if (char_index.find(s[end]) != char_index.end() && char_index[s[end]] >= start) {
            start = char_index[s[end]] + 1; // Cập nhật chỉ số bắt đầu
        }
        char_index[s[end]] = end; // Cập nhật vị trí ký tự hiện tại
        size_t current_length = end - start + 1; // Tính chiều dài đoạn con hiện tại

        // Chỉ cập nhật nếu chiều dài hiện tại lớn hơn chiều dài lớn nhất
        if (current_length > max_length) {
            max_length = current_length; // Cập nhật chiều dài lớn nhất
            max_start_index = start; // Cập nhật chỉ số bắt đầu của đoạn con lớn nhất
        }
    }

    return {max_start_index + 1, max_length}; // Chuyển đổi từ 0-based sang 1-based
}

int main() {
    string s;
    cout << "Nhập xâu kí tự S: ";
    cin >> s; 

    auto result = longest_unique_substring(s);
    cout << result.first << " " << result.second << endl; 

    return 0;
}
