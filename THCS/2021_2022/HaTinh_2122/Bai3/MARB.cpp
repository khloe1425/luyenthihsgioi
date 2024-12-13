#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Hằng số MOD để tránh tràn số
const int MOD = 1000000007;

int main() {
    ifstream input("MARB.INP");
    ofstream output("MARB.OUT");

    int n, m, k;
    input >> n >> m >> k;

    // Bảng dp[i][j]: Số cách phân phối j viên bi vào i hộp
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Base case: Không có viên bi nào, chỉ có 1 cách phân phối
    dp[0][0] = 1;

    // Duyệt qua từng hộp
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // Số cách phân phối khi không đặt thêm viên bi vào hộp i
            dp[i][j] = dp[i - 1][j];
            
            // Trừ đi các trường hợp dư (quá k viên bi trong 1 hộp)
            if (j > k) {
                dp[i][j] = (dp[i][j] - dp[i - 1][j - k - 1] + MOD) % MOD;
            }

            // Tích lũy số cách phân phối cho đến j viên bi
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    // Kết quả là số cách phân phối n viên bi vào m hộp
    output << dp[m][n] << endl;

    input.close();
    output.close();

    return 0;
}
