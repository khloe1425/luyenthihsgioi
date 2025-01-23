#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

const int INF = INT_MAX;
const int dx[] = {-1, 1, 0, 0}; // Hướng di chuyển: lên, xuống, trái, phải
const int dy[] = {0, 0, -1, 1};

int main() {
    ifstream input("BAI4.INP");
    ofstream output("BAI4.OUT");

    int N, M, x, y, z, t;
    input >> N >> M >> x >> y >> z >> t;

    // Đọc ma trận chi phí
    vector<vector<int>> grid(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            input >> grid[i][j];
        }
    }

    // Kiểm tra nếu ô xuất phát hoặc đích không hợp lệ
    if (grid[x][y] == 0 || grid[z][t] == 0) {
        output << -1 << endl;
        return 0;
    }

    // Mảng lưu chi phí ngắn nhất từ (x, y) đến mỗi ô
    vector<vector<int>> dist(N + 1, vector<int>(M + 1, INF));
    dist[x][y] = grid[x][y];

    // Hàng đợi ưu tiên để xử lý các ô
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({grid[x][y], x, y}); // {chi phí, dòng, cột}

    while (!pq.empty()) {
        auto [cost, u, v] = pq.top();
        pq.pop();

        // Nếu đã tìm được chi phí nhỏ nhất, không cần xử lý tiếp
        if (cost > dist[u][v]) continue;

        // Duyệt 4 hướng
        for (int i = 0; i < 4; ++i) {
            int nu = u + dx[i], nv = v + dy[i];

            // Kiểm tra ô hợp lệ
            if (nu >= 1 && nu <= N && nv >= 1 && nv <= M && grid[nu][nv] > 0) {
                int newCost = dist[u][v] + grid[nu][nv];
                if (newCost < dist[nu][nv]) {
                    dist[nu][nv] = newCost;
                    pq.push({newCost, nu, nv});
                }
            }
        }
    }

    // Kiểm tra kết quả
    if (dist[z][t] == INF) {
        output << -1 << endl; // Không tìm được đường đi
    } else {
        output << dist[z][t] << endl; // Ghi chi phí nhỏ nhất
    }

    input.close();
    output.close();

    return 0;
}
