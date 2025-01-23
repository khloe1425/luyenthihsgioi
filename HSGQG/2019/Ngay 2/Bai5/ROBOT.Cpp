#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>
using namespace std;

// Hướng di chuyển (trái, phải, lên, xuống)
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, maxPaths = 0; // Kích thước lưới và số đường hợp lệ tối đa
vector<string> grid; // Lưới đầu vào
vector<vector<bool>> visited; // Ma trận đánh dấu đã thăm

// Hàm kiểm tra một ô có hợp lệ hay không
bool isValid(int x, int y, int badCount) {
    return x >= 0 && x < 3 && y >= 0 && y < n &&
           grid[x][y] != '#' && !visited[x][y] &&
           (grid[x][y] != '*' || badCount < 1);
}

// DFS để tìm các đường đi hợp lệ
void dfs(int x, int y, int badCount, bool &foundT) {
    if (grid[x][y] == 'T') {
        foundT = true;
        return;
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, badCount)) {
            dfs(nx, ny, badCount + (grid[nx][ny] == '*' ? 1 : 0), foundT);
        }
    }

    visited[x][y] = false; // Backtrack
}

int main() {
    ifstream inputFile("ROBOT.INP");
    ofstream outputFile("ROBOT.OUT");

    // Đọc dữ liệu đầu vào
    inputFile >> n;
    grid.resize(3);
    for (int i = 0; i < 3; ++i) {
        inputFile >> grid[i];
    }

    // Duyệt tất cả các ô 'S' trong lưới
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'S') {
                visited.assign(3, vector<bool>(n, false));
                bool foundT = false;
                dfs(i, j, 0, foundT);
                if (foundT) maxPaths++;
            }
        }
    }

    // Ghi kết quả ra file
    outputFile << maxPaths << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
