#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Hàm tiền xử lý tổng tiền tố
void computePrefixSum(const vector<vector<int>> &a, vector<vector<int>> &prefix, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = a[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
}

// Hàm tính tổng giá trị của hình vuông r × r với góc trên trái (x, y)
int getSquareSum(const vector<vector<int>> &prefix, int x, int y, int r) {
    int x2 = x + r - 1, y2 = y + r - 1;
    return prefix[x2][y2] - prefix[x - 1][y2] - prefix[x2][y - 1] + prefix[x - 1][y - 1];
}

// Hàm giải bài toán
int solve(int n, int k, int r, int p, const vector<vector<int>> &a, const vector<vector<pair<int, int>>> &plans) {
    // Tiền xử lý mảng tổng tiền tố
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
    computePrefixSum(a, prefix, n);

    int maxSum = 0;

    // Duyệt qua từng phương án
    for (int i = 0; i < k; i++) {
        const auto &plan = plans[i];
        int currentSum = 0;
        bool valid = true;

        // Dùng mảng đánh dấu để kiểm tra giao nhau
        vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

        for (const auto &[x, y] : plan) {
            // Kiểm tra hình vuông có hợp lệ không
            for (int dx = 0; dx < r; dx++) {
                for (int dy = 0; dy < r; dy++) {
                    if (visited[x + dx][y + dy]) {
                        valid = false;
                        break;
                    }
                    visited[x + dx][y + dy] = true;
                }
                if (!valid) break;
            }

            // Nếu hợp lệ, cộng giá trị hình vuông
            if (valid) {
                currentSum += getSquareSum(prefix, x, y, r);
            } else {
                break;
            }
        }

        // Cập nhật tổng giá trị lớn nhất
        if (valid) {
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}

int main() {
    ifstream fin("BONUS.INP");
    ofstream fout("BONUS.OUT");

    int n, k, r, p;
    fin >> n >> k >> r >> p;

    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> a[i][j];
        }
    }

    vector<vector<pair<int, int>>> plans(k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < p; j++) {
            int x, y;
            fin >> x >> y;
            plans[i].emplace_back(x, y);
        }
    }

    fout << solve(n, k, r, p, a, plans) << endl;

    fin.close();
    fout.close();

    return 0;
}
