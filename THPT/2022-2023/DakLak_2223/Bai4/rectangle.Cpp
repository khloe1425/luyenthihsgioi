#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Hàm tìm tổng phần tử từ (r1, c1) đến (r2, c2) sử dụng bảng prefix sum
int getSum(const vector<vector<int>> &prefixSum, int r1, int c1, int r2, int c2) {
    int total = prefixSum[r2][c2];
    if (r1 > 0) total -= prefixSum[r1 - 1][c2];
    if (c1 > 0) total -= prefixSum[r2][c1 - 1];
    if (r1 > 0 && c1 > 0) total += prefixSum[r1 - 1][c1 - 1];
    return total;
}

int main() {
    ifstream inputFile("RECTANGLE.INP");
    ofstream outputFile("RECTANGLE.OUT");

    int t;
    inputFile >> t;

    while (t--) {
        int m, n, S;
        inputFile >> m >> n >> S;

        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                grid[i][j] = i * n + j;
            }
        }

        // Tính bảng prefix sum
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefixSum[i][j] = grid[i][j];
                if (i > 0) prefixSum[i][j] += prefixSum[i - 1][j];
                if (j > 0) prefixSum[i][j] += prefixSum[i][j - 1];
                if (i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i - 1][j - 1];
            }
        }

        int minArea = INT_MAX;
        for (int r1 = 0; r1 < m; ++r1) {
            for (int c1 = 0; c1 < n; ++c1) {
                for (int r2 = r1; r2 < m; ++r2) {
                    for (int c2 = c1; c2 < n; ++c2) {
                        int sum = getSum(prefixSum, r1, c1, r2, c2);
                        if (sum == S) {
                            int area = (r2 - r1 + 1) * (c2 - c1 + 1);
                            minArea = min(minArea, area);
                        }
                    }
                }
            }
        }

        if (minArea == INT_MAX) {
            outputFile << -1 << endl;
        } else {
            outputFile << minArea << endl;
        }
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
