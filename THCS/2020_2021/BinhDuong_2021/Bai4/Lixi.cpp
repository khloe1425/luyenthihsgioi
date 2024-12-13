#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Mở file input và output
    freopen("Lixi.INP", "r", stdin);
    freopen("Lixi.OUT", "w", stdout);

    int N;
    cin >> N; // Đọc giá trị N trực tiếp

    vector<vector<int>> money(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> money[i][j];
        }
    }

    // Quy hoạch động
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // Khởi tạo dp cho hàng đầu tiên
    for (int j = 0; j < N; ++j) {
        dp[0][j] = money[0][j];
    }

    // Tính dp cho các hàng tiếp theo
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int maxPrev = 0;
            // Tìm giá trị lớn nhất từ hàng trước đó mà không cùng cột
            for (int k = 0; k < N; ++k) {
                if (k != j) { // Không chọn cùng cột
                    maxPrev = max(maxPrev, dp[i - 1][k]);
                }
            }
            dp[i][j] = maxPrev + money[i][j];
        }
    }

    // Tìm kết quả lớn nhất từ hàng cuối cùng
    int maxMoney = 0;
    for (int j = 0; j < N; ++j) {
        maxMoney = max(maxMoney, dp[N - 1][j]);
    }

    cout << maxMoney << endl;

    return 0;
}
