#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm kiểm tra một chuỗi có đối xứng không
bool isPalindrome(const string& str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    ifstream inputFile("BAI04.INP");
    ofstream outputFile("BAI04.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    unordered_map<string, int> nameCount;
    vector<string> names;
    string name;

    // Đọc danh sách tên từ file
    while (inputFile >> name) {
        names.push_back(name);
        nameCount[name]++;
    }

    int uniqueCount = 0;    // Số tên xuất hiện 1 lần
    int palindromeCount = 0; // Số tên đối xứng

    for (const auto& entry : nameCount) {
        if (entry.second == 1) {
            uniqueCount++;
        }
        if (isPalindrome(entry.first)) {
            palindromeCount++;
        }
    }

    // Ghi kết quả ra file
    outputFile << uniqueCount << endl;
    outputFile << palindromeCount << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
