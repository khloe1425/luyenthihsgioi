#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Hàm kiểm tra xem một xâu có phải là đối xứng không
bool isPalindrome(const string &s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Hàm tìm chiều dài xâu con đối xứng dài nhất
int longestPalindromicSubstring(const string &s) {
    int maxLength = 1; // Chiều dài tối thiểu của xâu con đối xứng là 1
    int n = s.length();

    // Tìm xâu con đối xứng
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string substring = s.substr(i, j - i + 1);
            if (isPalindrome(substring)) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

int main() {
    ifstream infile("CAU04.INP");
    ofstream outfile("CAU04.OUT");

    int N;
    infile >> N; // Đọc chiều dài xâu S
    string S;
    infile >> S; // Đọc xâu S

    // Tìm chiều dài xâu con đối xứng dài nhất
    int longestLength = longestPalindromicSubstring(S);

    // Ghi kết quả ra tệp
    outfile << longestLength << endl;

    infile.close();
    outfile.close();
    return 0;
}
