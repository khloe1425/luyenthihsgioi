#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("DSDB.INP");
    ofstream fout("DSDB.OUT");

    int N;
    fin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        fin >> A[i];
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));

    // Khởi tạo bảng DP
    for (int i = 0; i < N; i++) {
        dp[i][i] = 1;
    }

    // Tính bảng DP
    for (int len = 2; len <= N; len++) {
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1;
            if (A[i] == A[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // Độ dài dãy con palindrome dài nhất
    int longest_palindrome = dp[0][N - 1];

    // Số phần tử cần chèn thêm
    int result = N - longest_palindrome;

    fout << result << endl;

    fin.close();
    fout.close();
    return 0;
}
