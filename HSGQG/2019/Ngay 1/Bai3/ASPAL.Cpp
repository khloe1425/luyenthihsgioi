#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const int MOD = 1e9 + 7;

// Hàm kiểm tra số đối xứng
bool isPalindrome(const string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l;
        --r;
    }
    return true;
}

// Hàm kiểm tra số gần siêu đối xứng
bool isNearSuperPalindrome(const string &s) {
    vector<int> freq(10, 0);
    for (char c : s) {
        freq[c - '0']++;
    }
    int oddCount = 0;
    for (int f : freq) {
        if (f % 2 != 0) {
            oddCount++;
        }
    }
    return oddCount <= 1;
}

int main() {
    ifstream inputFile("ASPAL.INP");
    ofstream outputFile("ASPAL.OUT");

    long long p, q;
    inputFile >> p >> q;

    long long count = 0;

    for (long long i = p; i <= q; ++i) {
        string num = to_string(i);
        if (isPalindrome(num) || isNearSuperPalindrome(num)) {
            count = (count + 1) % MOD;
        }
    }

    outputFile << count << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
