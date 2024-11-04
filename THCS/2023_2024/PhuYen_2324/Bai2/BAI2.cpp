
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm kiểm tra xem một từ có phải là từ đối xứng hay không
bool is_palindrome(const string &word) {
    int left = 0;
    int right = word.length() - 1;
    while (left < right) {
        if (word[left] != word[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    ifstream infile("BAI2.INP"); // Mở file để đọc
    ofstream outfile("BAI2.OUT"); // Mở file để ghi

    if (!infile) {
        cerr << "Không thể mở file BAI2.INP" << endl;
        return 1;
    }

    string line;
    getline(infile, line); // Đọc dòng đầu tiên
    infile.close(); // Đóng file đọc

    stringstream ss(line);
    string word;
    vector<string> palindromes;

    // Đọc từng từ trong chuỗi
    while (ss >> word) {
        if (word.length() >= 2 && is_palindrome(word)) {
            palindromes.push_back(word); // Lưu từ đối xứng vào vector
        }
    }

    // Tìm độ dài lớn nhất của các từ đối xứng
    int max_length = 0;
    for (const string &palindrome : palindromes) {
        max_length = max(max_length, (int)palindrome.length());
    }

    // Lưu các từ đối xứng có độ dài lớn nhất vào kết quả
    vector<string> longest_palindromes;
    for (const string &palindrome : palindromes) {
        if (palindrome.length() == max_length) {
            longest_palindromes.push_back(palindrome);
        }
    }

    // Ghi số lượng từ đối xứng và các từ đối xứng có độ dài lớn nhất vào file
    outfile << palindromes.size() << endl; // Số lượng từ đối xứng
    for (const string &lp : longest_palindromes) {
        outfile << lp << endl; // Ghi các từ đối xứng có độ dài lớn nhất
    }

    outfile.close(); // Đóng file ghi

    return 0;
}
