#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 500;
const int INF = INT_MAX;
int dx[] = {0, 1, 0, -1}; // Di chuyển theo 4 hướng
int dy[] = {1, 0, -1, 0};

int n, k;
bool grid[MAXN + 1][MAXN + 1];
int dist1[MAXN + 1][MAXN + 1];
int dist2[MAXN + 1][MAXN + 1];

// Hàm kiểm tra ô hợp lệ
bool isValid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n && grid[x][y];
}

// BFS từ vị trí ban đầu
void bfs(int startX, int startY, int dist[MAXN + 1][MAXN + 1]) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    dist[startX][startY] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ifstream fin("ROBOCON.INP");
    ofstream fout("ROBOCON.OUT");

    fin >> n >> k;

    // Khởi tạo lưới và các ô chướng ngại vật
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            grid[i][j] = true;
            dist1[i][j] = INF;
            dist2[i][j] = INF;
        }
    }

    // Đọc chướng ngại vật
    for (int i = 0; i < k; i++) {
        int x, y;
        fin >> x >> y;
        grid[x][y] = false;
    }

    // BFS cho robot 1 (từ góc trên trái)
    bfs(1, 1, dist1);

    // BFS cho robot 2 (từ góc dưới phải)
    bfs(n, n, dist2);

    // Tìm thời điểm gặp nhau sớm nhất
    int minTime = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist1[i][j] == dist2[i][j] && dist1[i][j] != INF) {
                minTime = min(minTime, dist1[i][j]);
            }
        }
    }

    if (minTime == INF) {
        fout << -1 << endl;
    } else {
        fout << minTime << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
