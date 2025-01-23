#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// Hàm kiểm tra lô hợp lệ
bool is_valid_lot(const vector<int>& heights, int start, int end, int w, int bmin, int bmax) {
    int inversions = 0;
    int sum = 0;

    for (int i = start; i <= end; i++) {
        if (i > start && heights[i] < heights[i - 1]) {
            inversions++;
        }
        sum += heights[i];
    }

    return (inversions <= w && sum >= bmin && sum <= bmax);
}

int main() {
    ifstream fin("ORGAN.INP");
    ofstream fout("ORGAN.OUT");

    int T;
    fin >> T;

    while (T--) {
        int n, s, w, m, bmin, bmax;
        fin >> n >> s >> w >> m >> bmin >> bmax;

        vector<int> heights(n + 1);
        for (int i = 1; i <= n; i++) {
            fin >> heights[i];
        }

        // Khởi tạo mảng DP
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        // Tính số cách phân lô
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (is_valid_lot(heights, j + 1, i, w, bmin, bmax)) {
                    dp[i] += dp[j];
                }
            }
        }

        // Đếm số cách thỏa mãn đủ s lô
        int result = 0;
        if (dp[n] >= s) {
            result = dp[n];
        } else {
            result = 0; // Không thể chia đủ s lô
        }

        fout << result << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
