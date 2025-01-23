#include <bits/stdc++.h>
using namespace std;

const int MAXN = 255;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int rows, cols;

// Các hướng di chuyển: lên, xuống, trái, phải
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Kiểm tra vị trí (x, y) hợp lệ
bool isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 'x' && !visited[x][y];
}

// DFS để đánh dấu các ô liên thông
void dfs(int x, int y) {
    visited[x][y] = true;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (isValid(nx, ny)) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("BAI2.INP");
    ofstream fout("BAI2.OUT");

    string line;
    rows = 0;

    // Đọc lưới từ file
    while (getline(fin, line)) {
        cols = line.size();
        for (int j = 0; j < cols; j++) {
            grid[rows][j] = line[j];
            visited[rows][j] = false;
        }
        rows++;
    }

    int shipCount = 0;

    // Duyệt từng ô trong lưới
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 'x' && !visited[i][j]) {
                shipCount++;  // Bắt đầu tìm một con tàu mới
                dfs(i, j);    // Đánh dấu các ô thuộc con tàu này
            }
        }
    }

    fout << shipCount << "\n";

    fin.close();
    fout.close();
    return 0;
}
