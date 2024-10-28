#include <iostream>
#include <fstream>
#include <string>

int expandAroundCenter(const std::string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // Độ dài của xâu con đối xứng
}

int longestPalindromeLength(const std::string& s) {
    if (s.empty()) return 0;

    int maxLength = 1; // Độ dài tối thiểu của palindrome là 1
    for (int i = 0; i < s.length(); ++i) {
        // Kiểm tra palindrome có độ dài lẻ
        int len1 = expandAroundCenter(s, i, i);
        // Kiểm tra palindrome có độ dài chẵn
        int len2 = expandAroundCenter(s, i, i + 1);
        maxLength = std::max(maxLength, std::max(len1, len2));
    }
    return maxLength;
}

int main() {
    // Đọc dữ liệu từ file PALIND.INP
    std::ifstream inputFile("PALIND.INP");
    std::string s;
    std::getline(inputFile, s); // Đọc toàn bộ xâu
    inputFile.close();

    // Tìm độ dài của xâu con đối xứng dài nhất
    int result = longestPalindromeLength(s);

    // Ghi kết quả vào file PALIND.OUT
    std::ofstream outputFile("PALIND.OUT");
    outputFile << result;
    outputFile.close();

    return 0;
}
