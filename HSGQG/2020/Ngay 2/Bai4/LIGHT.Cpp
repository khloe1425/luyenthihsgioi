#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <unordered_set>
using namespace std;

struct Switch {
    int r1, c1, r2, c2; // Vùng ảnh hưởng
};

// Chuyển đổi trạng thái của đèn
int nextState(int state) {
    return (state + 1) % 3;
}

// Thay đổi trạng thái của giàn đèn với công tắc
vector<vector<int>> applySwitch(const vector<vector<int>> &grid, const Switch &sw) {
    vector<vector<int>> newGrid = grid;
    for (int i = sw.r1; i <= sw.r2; ++i) {
        for (int j = sw.c1; j <= sw.c2; ++j) {
            newGrid[i][j] = nextState(newGrid[i][j]);
        }
    }
    return newGrid;
}

// Kiểm tra xem giàn đèn có cùng trạng thái không
bool isUniform(const vector<vector<int>> &grid) {
    int firstState = grid[0][0];
    for (const auto &row : grid) {
        for (int state : row) {
            if (state != firstState) return false;
        }
    }
    return true;
}

// Chuyển đổi trạng thái giàn đèn thành chuỗi để lưu trữ trong set
string gridToString(const vector<vector<int>> &grid) {
    string result;
    for (const auto &row : grid) {
        for (int state : row) {
            result += to_string(state);
        }
    }
    return result;
}

int main() {
    // Đọc dữ liệu từ file
    ifstream inputFile("LIGHT.INP");
    ofstream outputFile("LIGHT.OUT");

    int m, n, k;
    inputFile >> m >> n >> k;

    // Trạng thái ban đầu của giàn đèn
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> grid[i][j];
        }
    }

    // Danh sách công tắc
    vector<Switch> switches(k);
    for (int i = 0; i < k; ++i) {
        inputFile >> switches[i].r1 >> switches[i].c1 >> switches[i].r2 >> switches[i].c2;
        switches[i].r1--;
        switches[i].c1--;
        switches[i].r2--;
        switches[i].c2--;
    }

    // BFS để tìm số lần tác động ít nhất
    queue<pair<vector<vector<int>>, int>> q; // {Trạng thái giàn đèn, số lần tác động}
    unordered_set<string> visited;          // Trạng thái đã duyệt

    q.push({grid, 0});
    visited.insert(gridToString(grid));

    while (!q.empty()) {
        auto [currentGrid, steps] = q.front();
        q.pop();

        // Kiểm tra nếu tất cả đèn đã cùng trạng thái
        if (isUniform(currentGrid)) {
            outputFile << steps << endl;
            inputFile.close();
            outputFile.close();
            return 0;
        }

        // Thử tác động từng công tắc
        for (const auto &sw : switches) {
            vector<vector<int>> newGrid = applySwitch(currentGrid, sw);
            string newState = gridToString(newGrid);

            if (visited.find(newState) == visited.end()) {
                q.push({newGrid, steps + 1});
                visited.insert(newState);
            }
        }
    }

    // Nếu không thể đưa về cùng trạng thái
    outputFile << -1 << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
