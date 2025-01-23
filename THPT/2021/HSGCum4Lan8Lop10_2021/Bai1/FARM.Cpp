#include <bits/stdc++.h>
using namespace std;

const int MAX = 105; 
int M, N, K;          
int grid[MAX][MAX];   
bool visited[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(queue<pair<int, int>>& q) {
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < M && nc >= 0 && nc < N && !visited[nr][nc] && grid[nr][nc] == 0) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("FARM.INP");
    ofstream fout("FARM.OUT");

    fin >> M >> N >> K;
    memset(grid, 0, sizeof(grid));
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    for (int i = 0; i < K; ++i) {
        int r, c;
        fin >> r >> c;
        r--; c--; // Chuyển về chỉ số 0-based
        grid[r][c] = 1;
        visited[r][c] = true;
        q.push({r, c});
    }

    bfs(q);

    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j] && grid[i][j] == 0) {
                cnt++;
            }
        }
    }

    fout << cnt << "\n";

    fin.close();
    fout.close();
    return 0;
}
