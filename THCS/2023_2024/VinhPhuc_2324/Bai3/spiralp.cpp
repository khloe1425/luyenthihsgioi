#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Cấu trúc để lưu thông tin ô trên lưới
struct Cell {
    int x, y; // tọa độ
};

// Hàm kiểm tra xem ô có hợp lệ không
bool isValid(int x, int y, int N, int M, vector<vector<int>>& grid) {
    return (x >= 0 && x < N && y >= 0 && y < M && grid[x][y] == 0);
}

// Hàm tìm số bước tối thiểu để đến ô (N, M)
int bfsMinSteps(int N, int M, int K, vector<vector<int>>& grid) {
    queue<Cell> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    q.push({0, 0});
    visited[0][0] = true;

    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Cell cell = q.front();
            q.pop();

            // Kiểm tra nếu đã đến đích
            if (cell.x == N - 1 && cell.y == M - 1) {
                return steps;
            }

            // Thực hiện di chuyển từ ô hiện tại
            int currentIndex = cell.x * M + cell.y + 1; // Đánh số ô bắt đầu từ 1
            for (int move = 1; move <= K; ++move) {
                for (int j = 0; j <= move; ++j) {
                    int newX = cell.x + (move - j);  // Di chuyển xuống
                    int newY = cell.y + j;            // Di chuyển sang phải

                    if (isValid(newX, newY, N, M, grid) && !visited[newX][newY]) {
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
        }
        steps++;
    }

    return -1; // Nếu không đến được ô (N, M)
}

// Hàm tính số cách di chuyển hợp lệ
void calculateWays(int N, int M, int K, vector<vector<int>>& grid, vector<int>& ways) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 0) { // Nếu ô là trắng
                int index = i * M + j + 1;
                for (int move = 1; move <= K; ++move) {
                    for (int jMove = 1; jMove <= move; ++jMove) {
                        int newX = i + (move - jMove);
                        int newY = j + jMove;

                        if (isValid(newX, newY, N, M, grid)) {
                            ways[index]++;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    // Đọc dữ liệu
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    // Tính số bước tối thiểu
    int minSteps = bfsMinSteps(N, M, K, grid);

    // Tính số cách di chuyển hợp lệ
    vector<int> ways(N * M + 1, 0);
    calculateWays(N, M, K, grid, ways);

    // Tìm giá trị max(F(1), F(2), ..., F(N*M))
    int maxWays = *max_element(ways.begin() + 1, ways.end());

    // In kết quả
    cout << minSteps << " " << maxWays << endl;

    return 0;
}
