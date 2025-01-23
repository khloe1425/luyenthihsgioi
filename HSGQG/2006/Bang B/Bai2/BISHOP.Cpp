#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct Position {
    int x, y, steps;
};

bool isValid(int x, int y, int n, vector<vector<int>>& board) {
    return x >= 1 && x <= n && y >= 1 && y <= n && board[x][y] == 0;
}

bool onSameDiagonal(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) == abs(y1 - y2);
}

int bfs(int n, int m, int p, int q, int s, int t, vector<pair<int, int>>& obstacles) {
    vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));

    // Đặt các quân cờ chặn
    for (auto& obs : obstacles) {
        board[obs.first][obs.second] = 1;
    }

    if (board[p][q] == 1 || board[s][t] == 1) return -1;

    queue<Position> qPos;
    qPos.push({p, q, 0});

    while (!qPos.empty()) {
        auto current = qPos.front();
        qPos.pop();

        if (current.x == s && current.y == t) return current.steps;

        if (current.steps >= 2) continue;

        for (int dx = -1; dx <= 1; dx += 2) {
            for (int dy = -1; dy <= 1; dy += 2) {
                int nx = current.x, ny = current.y;
                while (isValid(nx + dx, ny + dy, n, board)) {
                    nx += dx;
                    ny += dy;
                    if (nx == s && ny == t) return current.steps + 1;
                    qPos.push({nx, ny, current.steps + 1});
                }
            }
        }
    }

    return -1;
}

int main() {
    ifstream input("BISHOP.INP");
    ofstream output("BISHOP.OUT");

    int n, m, p, q, s, t;
    input >> n >> m >> p >> q >> s >> t;

    vector<pair<int, int>> obstacles(m);
    for (int i = 0; i < m; i++) {
        input >> obstacles[i].first >> obstacles[i].second;
    }

    int result = bfs(n, m, p, q, s, t, obstacles);

    output << result << endl;

    input.close();
    output.close();

    return 0;
}
