#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Cấu trúc để lưu thông tin quả bóng
struct Ball {
    int value, row, col;
};

// So sánh giá trị quả bóng
bool compareBall(const Ball &a, const Ball &b) {
    return a.value > b.value;
}

int main() {
    ifstream inputFile("LINE.INP");
    ofstream outputFile("LINE.OUT");

    int m, n, k;
    inputFile >> m >> n >> k;

    vector<vector<int>> grid(m, vector<int>(n));
    vector<Ball> balls;

    // Đọc ma trận và lưu các quả bóng vào danh sách
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> grid[i][j];
            balls.push_back({grid[i][j], i, j});
        }
    }

    // Sắp xếp quả bóng theo giá trị giảm dần
    sort(balls.begin(), balls.end(), compareBall);

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int totalValue = 0;
    int hits = 0;

    for (const auto &ball : balls) {
        if (hits >= k) break;

        int row = ball.row;
        int col = ball.col;

        // Nếu quả bóng chưa bị đập
        if (!visited[row][col]) {
            totalValue += ball.value;
            ++hits;

            // Đánh dấu các quả bóng bị vỡ
            queue<pair<int, int>> q;
            q.push({row, col});
            visited[row][col] = true;

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                static const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
                for (const auto &[dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] > 0) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    outputFile << totalValue << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
