#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

const int MOD = 1000000007; // Nếu cần modulo để tránh tràn số nguyên

int main() {
    // Đọc dữ liệu từ file SMARKET.INP
    ifstream inputFile("SMARKET.INP");
    ofstream outputFile("SMARKET.OUT");

    int s, n; // s: số tiền cần sử dụng, n: số mặt hàng
    inputFile >> s >> n;

    vector<int> c(n), m(n);
    for (int i = 0; i < n; i++) {
        inputFile >> c[i] >> m[i]; // c[i]: giá tiền mỗi mặt hàng, m[i]: số lượng tối đa
    }

    // Mảng dp để lưu số cách sử dụng hết x đồng
    vector<int> dp(s + 1, 0);
    dp[0] = 1; // Có 1 cách để sử dụng 0 đồng: không mua gì cả

    // Mảng để ghi nhận truy vết
    vector<vector<int>> ways(n, vector<int>(s + 1, 0));

    // Duyệt qua từng mặt hàng
    for (int i = 0; i < n; i++) {
        // Duyệt qua số tiền từ s -> 0
        for (int j = s; j >= 0; j--) {
            for (int k = 1; k <= m[i] && j >= k * c[i]; k++) {
                dp[j] = (dp[j] + dp[j - k * c[i]]) % MOD;
                ways[i][j] = max(ways[i][j], ways[i][j - k * c[i]] + k);
            }
        }
    }

    // Ghi số cách ra file
    outputFile << dp[s] << endl;

    // Tìm số lượng từng mặt hàng được mua trong cách bất kỳ
    vector<int> result(n, 0);
    int remaining = s;

    for (int i = n - 1; i >= 0; i--) {
        for (int k = 0; k <= m[i]; k++) {
            if (remaining >= k * c[i] && dp[remaining - k * c[i]] > 0) {
                result[i] = k;
                remaining -= k * c[i];
                break;
            }
        }
    }

    // Ghi kết quả ra file (số lượng từng mặt hàng được mua)
    for (int i = 0; i < n; i++) {
        outputFile << result[i] << " ";
    }
    outputFile << endl;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
