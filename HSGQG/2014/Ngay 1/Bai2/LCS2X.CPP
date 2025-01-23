#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm xử lý cho từng bộ dữ liệu
int findLongestCommonSubsequence(const vector<int>& A, const vector<int>& B) {
    int m = A.size(), n = B.size();

    // Tạo bảng dp với kích thước m x n
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1] && (dp[i - 1][j - 1] == 0 || A[i - 1] >= 2 * A[dp[i - 1][j - 1] - 1])) {
                // Nếu phần tử tương đồng và thoả điều kiện 2*c[i] <= c[i+1]
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Chọn giá trị lớn nhất giữa việc bỏ qua phần tử từ A hoặc từ B
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    ifstream fin("LCS2X.INP");
    ofstream fout("LCS2X.OUT");

    int T;
    fin >> T;

    while (T--) {
        int m, n;
        fin >> m >> n;

        vector<int> A(m), B(n);

        for (int i = 0; i < m; ++i) {
            fin >> A[i];
        }

        for (int i = 0; i < n; ++i) {
            fin >> B[i];
        }

        int result = findLongestCommonSubsequence(A, B);
        fout << result << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
