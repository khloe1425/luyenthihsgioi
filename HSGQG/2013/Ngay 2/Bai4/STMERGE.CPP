#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

const int INF = 1e9;

int main() {
    ifstream fin("STMERGE.INP");
    ofstream fout("STMERGE.OUT");

    int t;
    fin >> t;

    while (t--) {
        int m, n;
        fin >> m >> n;

        vector<int> X(m + 1), Y(n + 1);

        // Đọc xâu X
        for (int i = 1; i <= m; i++) {
            fin >> X[i];
        }

        // Đọc xâu Y
        for (int j = 1; j <= n; j++) {
            fin >> Y[j];
        }

        // Đọc bảng chi phí
        vector<vector<int>> cost(101, vector<int>(101, 0)); // Giả sử giá trị tối đa là 100
        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= 100; j++) {
                fin >> cost[i][j];
            }
        }

        // Khởi tạo mảng DP
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        // Khởi tạo hàng đầu tiên và cột đầu tiên
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] + cost[X[i]][X[i - 1]];
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] + cost[Y[j]][Y[j - 1]];
        }

        // Tính toán DP
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(
                    dp[i - 1][j] + cost[X[i]][X[i - 1]], 
                    min(dp[i][j - 1] + cost[Y[j]][Y[j - 1]], 
                        dp[i - 1][j - 1] + cost[X[i]][Y[j]])
                );
            }
        }

        // Kết quả
        fout << dp[m][n] << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
