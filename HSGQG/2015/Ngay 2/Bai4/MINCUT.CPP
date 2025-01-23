#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Hàm tính tổng tiền tố
void calculatePrefixSum(const vector<vector<int>>& grid, vector<vector<int>>& prefixSum, int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefixSum[i][j] = grid[i-1][j-1] 
                            + prefixSum[i-1][j] 
                            + prefixSum[i][j-1] 
                            - prefixSum[i-1][j-1];
        }
    }
}

// Hàm tính tổng của hình chữ nhật từ `(x1, y1)` đến `(x2, y2)`
int getRectangleSum(const vector<vector<int>>& prefixSum, int x1, int y1, int x2, int y2) {
    return prefixSum[x2][y2]
         - prefixSum[x1-1][y2]
         - prefixSum[x2][y1-1]
         + prefixSum[x1-1][y1-1];
}

int main() {
    ifstream input("MINCUT.INP");
    ofstream output("MINCUT.OUT");

    int m, n, k;
    input >> m >> n >> k;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            input >> grid[i][j];
        }
    }

    vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
    calculatePrefixSum(grid, prefixSum, m, n);

    while (k--) {
        int x1, y1, x2, y2;
        input >> x1 >> y1 >> x2 >> y2;

        int minDiff = INT_MAX;
        int totalSum = getRectangleSum(prefixSum, x1, y1, x2, y2);

        // Thử cắt ngang
        for (int i = x1; i < x2; i++) {
            int upperSum = getRectangleSum(prefixSum, x1, y1, i, y2);
            int lowerSum = totalSum - upperSum;
            minDiff = min(minDiff, abs(upperSum - lowerSum));
        }

        // Thử cắt dọc
        for (int j = y1; j < y2; j++) {
            int leftSum = getRectangleSum(prefixSum, x1, y1, x2, j);
            int rightSum = totalSum - leftSum;
            minDiff = min(minDiff, abs(leftSum - rightSum));
        }

        output << minDiff << endl;
    }

    input.close();
    output.close();
    return 0;
}
