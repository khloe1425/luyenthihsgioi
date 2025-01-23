#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_M = 10;
const int MAX_N = 10;

int m, n;
char board[MAX_M][MAX_N];
bool visited[MAX_M][MAX_N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void bfs(int x, int y, char target) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (isValid(nx, ny) && !visited[nx][ny] && board[nx][ny] == target) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int countRegions() {
    memset(visited, false, sizeof(visited));
    int regions = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j] && board[i][j] != '.') {
                ++regions;
                bfs(i, j, board[i][j]);
            }
        }
    }

    return regions;
}

int main() {
    ifstream infile("CHANGE.INP");
    ofstream outfile("CHANGE.OUT");

    infile >> m >> n;
    for (int i = 0; i < m; ++i) {
        infile >> board[i];
    }

    int maxRemoved = 0;

    // Thử xóa từng cặp ô giống nhau
    for (int x1 = 0; x1 < m; ++x1) {
        for (int y1 = 0; y1 < n; ++y1) {
            for (int x2 = 0; x2 < m; ++x2) {
                for (int y2 = 0; y2 < n; ++y2) {
                    if ((x1 != x2 || y1 != y2) && board[x1][y1] == board[x2][y2] && board[x1][y1] != '.') {
                        // Xóa hai ô
                        char temp1 = board[x1][y1];
                        char temp2 = board[x2][y2];
                        board[x1][y1] = board[x2][y2] = '.';

                        // Đếm số vùng còn lại
                        int regions = countRegions();
                        maxRemoved = max(maxRemoved, regions);

                        // Khôi phục lại
                        board[x1][y1] = temp1;
                        board[x2][y2] = temp2;
                    }
                }
            }
        }
    }

    outfile << maxRemoved << endl;

    infile.close();
    outfile.close();

    return 0;
}
