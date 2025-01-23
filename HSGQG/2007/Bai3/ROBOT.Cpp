#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, time, cost;
};

int main() {
    // Đọc dữ liệu từ file ROBOT.INP
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);

    int n, m, w;
    cin >> n;

    vector<int> has_station(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> has_station[i];
    }

    cin >> w >> m;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, t, c;
        cin >> u >> v >> t >> c;
        graph[u].push_back({v, t, c});
    }

    // Mảng dist lưu thời gian tối thiểu để đến mỗi nút với mức năng lượng cụ thể
    vector<vector<int>> dist(n + 1, vector<int>(w + 1, INF));
    dist[1][w] = 0; // Bắt đầu từ nút 1 với năng lượng đầy

    // Hàng đợi ưu tiên lưu các trạng thái: {thời gian hiện tại, nút, năng lượng còn lại}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, 1, w});

    while (!pq.empty()) {
        auto [current_time, u, fuel] = pq.top();
        pq.pop();

        // Nếu trạng thái này không còn tối ưu, bỏ qua
        if (current_time > dist[u][fuel]) continue;

        // Nếu có trạm tiếp năng lượng tại nút này, cập nhật trạng thái với năng lượng đầy
        if (has_station[u] && dist[u][w] > current_time) {
            dist[u][w] = current_time;
            pq.push({current_time, u, w});
        }

        // Xét các cạnh từ nút hiện tại
        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int t = edge.time;
            int c = edge.cost;

            // Nếu đủ năng lượng để đi đến nút tiếp theo
            if (fuel >= c && dist[v][fuel - c] > current_time + t) {
                dist[v][fuel - c] = current_time + t;
                pq.push({current_time + t, v, fuel - c});
            }
        }
    }

    // Tìm thời gian tối thiểu để đến nút n
    int result = INF;
    for (int fuel = 0; fuel <= w; fuel++) {
        result = min(result, dist[n][fuel]);
    }

    // Ghi kết quả ra file
    if (result == INF) {
        cout << -1 << endl; // Không thể đến nút n
    } else {
        cout << result << endl; // Thời gian ngắn nhất
    }

    return 0;
}
