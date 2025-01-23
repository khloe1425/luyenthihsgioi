#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Hàm kiểm tra chuỗi đối xứng
bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Hàm tìm độ dài chuỗi đối xứng dài nhất
int longestPalindrome(const string& s) {
    int maxLength = 1; // Chuỗi đối xứng dài nhất ít nhất có độ dài 1
    int n = s.size();

    for (int center = 0; center < n; ++center) {
        // Kiểm tra chuỗi đối xứng có tâm là một ký tự (lẻ)
        for (int radius = 0; center - radius >= 0 && center + radius < n; ++radius) {
            if (s[center - radius] == s[center + radius]) {
                int currentLength = 2 * radius + 1;
                maxLength = max(maxLength, currentLength);
            } else {
                break;
            }
        }

        // Kiểm tra chuỗi đối xứng có tâm là giữa hai ký tự (chẵn)
        for (int radius = 0; center - radius >= 0 && center + radius + 1 < n; ++radius) {
            if (s[center - radius] == s[center + radius + 1]) {
                int currentLength = 2 * (radius + 1);
                maxLength = max(maxLength, currentLength);
            } else {
                break;
            }
        }
    }

    return maxLength;
}

int main() {
    ifstream inputFile("CHUOI.INP");
    ofstream outputFile("CHUOI.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    string s;
    inputFile >> s;

    int result = longestPalindrome(s);

    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
