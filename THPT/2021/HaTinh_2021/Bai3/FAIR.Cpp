#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MOD = 123456789;

int main() {
    ifstream inputFile("FAIR.INP");  // Mở file đầu vào
    ofstream outputFile("FAIR.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n, S;
    inputFile >> n >> S;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> a[i];
    }

    // Khởi tạo mảng dp
    vector<long long> dp(S + 1, 0);
    dp[0] = 1; // Có 1 cách để tạo ra tổng 0 (không chọn món nào)

    // Duyệt qua từng món hàng
    for (int i = 0; i < n; ++i) {
        for (int j = S; j >= a[i]; --j) {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }

    // Kết quả là dp[S]
    outputFile << dp[S] << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
