#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9; // Để tính số cách di chuyển lớn, nếu cần thiết
int m, n;
vector<vector<int>> grid;
vector<vector<long long>> dp;

bool isValid(int i1, int j1, int i2, int j2) {
    if (i2 < 0 || i2 >= m || j2 < 0 || j2 >= n) return false; // Ngoài lưới
    if (j2 <= j1) return false;                              // Không đi ngược
    if (i1 + j1 >= i2 + j2) return false;                    // Không vi phạm điều kiện
    if (__gcd(grid[i1][j1], grid[i2][j2]) == 1) return false; // Ước chung lớn hơn 1
    return true;
}

int main() {
    ifstream input("NETPATH.INP");
    ofstream output("NETPATH.OUT");

    input >> m >> n;
    grid.resize(m, vector<int>(n));
    dp.resize(m, vector<long long>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            input >> grid[i][j];
        }
    }

    // Khởi tạo DP cho cột đầu tiên
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1; // Mỗi ô ở cột đầu tiên là điểm bắt đầu
    }

    // Tính toán số cách di chuyển
    for (int j = 0; j < n - 1; ++j) {
        for (int i = 0; i < m; ++i) {
            if (dp[i][j] == 0) continue; // Không có cách nào tới đây
            for (int i2 = 0; i2 < m; ++i2) {
                if (isValid(i, j, i2, j + 1)) {
                    dp[i2][j + 1] = (dp[i2][j + 1] + dp[i][j]) % MOD;
                }
            }
        }
    }

    // Tính tổng số cách di chuyển tới cột cuối cùng
    long long result = 0;
    for (int i = 0; i < m; ++i) {
        result = (result + dp[i][n - 1]) % MOD;
    }

    output << result << endl;

    input.close();
    output.close();

    return 0;
}
