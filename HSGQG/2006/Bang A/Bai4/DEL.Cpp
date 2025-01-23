#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int MAX_M = 20;
const int MAX_N = 20;

int m, n, r1, c1, r2, c2;
char grid[MAX_M][MAX_N];
bool visited[MAX_M][MAX_N];

bool isValid(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '.' && !visited[x][y];
}

int bfs(int sx, int sy, int ex, int ey) {
    memset(visited, false, sizeof(visited));
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, 0});
    visited[sx][sy] = true;

    while (!q.empty()) {
        auto [x, y, steps] = q.front();
        q.pop();

        if (x == ex && y == ey) return steps;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                q.push({nx, ny, steps + 1});
            }
        }
    }
    return -1; // Không thể tới đích
}

int main() {
    // Mở file input và output
    ifstream input("DEL.INP");
    ofstream output("DEL.OUT");

    // Đọc input
    input >> m >> n >> r1 >> c1 >> r2 >> c2;
    for (int i = 0; i < m; i++) {
        input >> grid[i];
    }

    // Chạy BFS để tính toán
    int result = bfs(r1 - 1, c1 - 1, r2 - 1, c2 - 1);

    // Ghi kết quả ra file
    output << result << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
