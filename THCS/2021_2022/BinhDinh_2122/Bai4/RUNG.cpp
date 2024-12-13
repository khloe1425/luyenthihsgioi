#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

const int MAX_N = 50;
const int dx[] = {-1, 1, 0, 0}; // Hướng đi: Bắc, Nam, Tây, Đông
const int dy[] = {0, 0, -1, 1};

int N; // Kích thước ma trận
int startX, startY; // Tọa độ ban đầu
int grid[MAX_N][MAX_N]; // Ma trận khu rừng
int dist[MAX_N][MAX_N]; // Khoảng cách từ ô bắt đầu
pair<int, int> parent[MAX_N][MAX_N]; // Truy vết đường đi

// Kiểm tra xem ô (x, y) có hợp lệ và an toàn không
bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == 0;
}

int main() {
    // Đọc dữ liệu từ file RUNG.INP
    ifstream input("RUNG.INP");
    ofstream output("RUNG.OUT");

    input >> N;
    input >> startX >> startY;

    // Chuyển tọa độ từ 1-based sang 0-based
    startX--;
    startY--;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            input >> grid[i][j];
            dist[i][j] = -1; // Đặt khoảng cách ban đầu là -1
            parent[i][j] = {-1, -1}; // Không có cha ban đầu
        }
    }

    // BFS để tìm đường thoát
    queue<pair<int, int>> q;
    q.push({startX, startY});
    dist[startX][startY] = 0;

    pair<int, int> exitPoint = {-1, -1}; // Điểm thoát
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Kiểm tra nếu thoát ra ngoài biên
        if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
            exitPoint = {x, y};
            break; // Dừng ngay khi tìm thấy điểm thoát
        }

        // Duyệt 4 hướng
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (isValid(nx, ny) && dist[nx][ny] == -1) { // Nếu ô hợp lệ và chưa thăm
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y}; // Lưu cha để truy vết
                q.push({nx, ny});
            }
        }
    }

    if (exitPoint.first == -1) {
        // Không tìm được đường thoát
        output << 0 << endl;
    } else {
        // Truy vết lại đường đi
        vector<pair<int, int>> path;
        int x = exitPoint.first, y = exitPoint.second;
        while (x != startX || y != startY) {
            path.push_back({x, y});
            tie(x, y) = parent[x][y]; // Lấy ô cha
        }
        path.push_back({startX, startY});

        // Ghi kết quả
        output << dist[exitPoint.first][exitPoint.second] << endl; // Số bước ít nhất
        output << path.size() - 1 << endl; // Số ô trên đường đi (không tính ô xuất phát)
        for (int i = path.size() - 1; i >= 0; i--) {
            output << path[i].first + 1 << " " << path[i].second + 1 << endl; // +1 để chuyển về 1-based
        }
    }

    input.close();
    output.close();
    return 0;
}
