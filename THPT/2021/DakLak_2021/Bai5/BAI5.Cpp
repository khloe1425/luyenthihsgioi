#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

// Hướng di chuyển (trái, phải, lên, xuống)
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dijkstra(const vector<vector<int>> &grid, int M, int N, int x1, int y1, int x2, int y2) {
    vector<vector<int>> dist(M, vector<int>(N, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Bắt đầu từ (x1, y1)
    pq.push({0, x1, y1});
    dist[x1][y1] = 0;

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top();
        pq.pop();

        // Nếu đến (x2, y2), trả về kết quả
        if (x == x2 && y == y2) return cost;

        // Kiểm tra các hướng di chuyển
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                int new_cost = cost;

                // Tính chi phí leo
                if (grid[nx][ny] == grid[x][y])
                    new_cost += 1; // Cùng mặt phẳng ngang
                else
                    new_cost += 2; // Khác độ cao

                if (new_cost < dist[nx][ny]) {
                    dist[nx][ny] = new_cost;
                    pq.push({new_cost, nx, ny});
                }
            }
        }
    }
    return -1; // Không tìm thấy đường đi
}

int main() {
    ifstream inputFile("BAI5.INP");
    ofstream outputFile("BAI5.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int M, N;
    inputFile >> M >> N;

    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> grid[i][j];
        }
    }

    int x1, y1, x2, y2;
    inputFile >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--; // Chuyển về chỉ số 0-based

    int result = dijkstra(grid, M, N, x1, y1, x2, y2);
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
