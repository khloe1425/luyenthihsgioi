#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;
int n;
int a[4][10000];
int dp[10000][16];

// Kiểm tra hai trạng thái có hợp lệ khi chuyển từ cột trước sang cột hiện tại
bool isValid(int mask1, int mask2) {
    for (int i = 0; i < 4; i++) {
        if ((mask1 & (1 << i)) && (mask2 & (1 << i))) return false;
        if (i < 3 && (mask1 & (1 << i)) && (mask2 & (1 << (i + 1)))) return false;
    }
    return true;
}

// Tính tổng trọng lượng của trạng thái `mask` ở cột `j`
int getWeight(int mask, int col) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (mask & (1 << i)) sum += a[i][col];
    }
    return sum;
}

int main() {
    // Đọc dữ liệu
    ifstream fin("SELECT.INP");
    ofstream fout("SELECT.OUT");

    fin >> n;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            fin >> a[i][j];
        }
    }

    // Khởi tạo DP
    for (int mask = 0; mask < 16; mask++) {
        dp[0][mask] = getWeight(mask, 0);
    }

    // Quy hoạch động
    for (int j = 1; j < n; j++) {
        for (int mask = 0; mask < 16; mask++) {
            dp[j][mask] = INF;
            for (int prevMask = 0; prevMask < 16; prevMask++) {
                if (isValid(prevMask, mask)) {
                    dp[j][mask] = max(dp[j][mask], dp[j - 1][prevMask] + getWeight(mask, j));
                }
            }
        }
    }

    // Tìm kết quả lớn nhất
    int result = INF;
    for (int mask = 0; mask < 16; mask++) {
        result = max(result, dp[n - 1][mask]);
    }

    fout << result << endl;
    fin.close();
    fout.close();
    return 0;
}
