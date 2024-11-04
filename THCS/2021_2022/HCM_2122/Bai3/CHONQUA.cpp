#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm tính mảng tổng cộng dồn
vector<vector<int>> calculatePrefixSum(const vector<string>& grid, int D, int R) {
    vector<vector<int>> prefixSum(D + 1, vector<int>(R + 1, 0));
    
    for (int i = 1; i <= D; i++) {
        for (int j = 1; j <= R; j++) {
            prefixSum[i][j] = (grid[i - 1][j - 1] == '*' ? 1 : 0) 
                            + prefixSum[i - 1][j]
                            + prefixSum[i][j - 1]
                            - prefixSum[i - 1][j - 1];
        }
    }
    
    return prefixSum;
}

// Hàm tính tổng số '*' trong hình chữ nhật từ (x1, y1) đến (x2, y2)
int getSum(const vector<vector<int>>& prefixSum, int x1, int y1, int x2, int y2) {
    return prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1];
}

// Hàm tính số lượng quà tối đa An có thể nhận
int maxGifts(int D, int R, int K, const vector<string>& grid) {
    vector<vector<int>> prefixSum = calculatePrefixSum(grid, D, R);
    int maxGifts = 0;

    for (int i = 1; i <= D - K + 1; i++) {
        for (int j = 1; j <= R - K + 1; j++) {
            // Tính số '*' bên trong khung K-2 x K-2
            int innerGifts = getSum(prefixSum, i + 1, j + 1, i + K - 2, j + K - 2);
            maxGifts = max(maxGifts, innerGifts);
        }
    }

    return maxGifts;
}

int main() {
    ifstream inputFile("CHONQUA.INP");
    ofstream outputFile("CHONQUA.OUT");

    int D, R, K;
    inputFile >> D >> R >> K;
    vector<string> grid(D);

    for (int i = 0; i < D; i++) {
        inputFile >> grid[i];
    }

    int result = maxGifts(D, R, K, grid);
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}