#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream infile("ROBOT.INP");
    ofstream outfile("ROBOT.OUT");

    int N, M, Q, K;
    infile >> N >> M >> Q >> K;

    vector<vector<int>> A(N + 1, vector<int>(M + 1));
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(M + 1, vector<int>(K, 0)));

    // Đọc bảng A
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            infile >> A[i][j];
        }
    }

    // Khởi tạo giá trị ban đầu
    dp[1][1][A[1][1] % K] = 1;

    // Tính toán số ô có thể đi qua thỏa mãn điều kiện
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (i == 1 && j == 1) continue; // Bỏ qua ô (1, 1)
            for (int mod = 0; mod < K; ++mod) {
                if (i > 1) {
                    dp[i][j][mod] += dp[i - 1][j][mod]; // Từ ô trên
                }
                if (j > 1) {
                    dp[i][j][mod] += dp[i][j - 1][mod]; // Từ ô bên trái
                }
                if (i > 1 && j > 1) {
                    dp[i][j][mod] -= dp[i - 1][j - 1][mod]; // Trừ ô chéo
                }
            }

            int modValue = A[i][j] % K;
            dp[i][j][modValue]++; // Tăng số lượng ô thỏa mãn
        }
    }

    // Xử lý các truy vấn
    for (int i = 0; i < Q; ++i) {
        int X;
        infile >> X;

        // Kết quả cho mỗi truy vấn là tổng số ô có thể đi qua thỏa mãn A[i][j] mod K = X
        int result = dp[N][M][X];

        outfile << result << endl; // Kết quả cho mỗi truy vấn
    }

    infile.close();
    outfile.close();
    return 0;
}
