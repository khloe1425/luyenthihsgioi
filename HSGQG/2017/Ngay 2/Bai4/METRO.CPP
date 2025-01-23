#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
using namespace std;

struct Edge {
    int to;         // Nút đích
    int time;       // Thời gian di chuyển qua cạnh này
    int line;       // Tuyến đường
};

const long long INF = LLONG_MAX;

struct State {
    int node;       // Nút hiện tại
    long long time; // Thời gian di chuyển
    int line;       // Tuyến đường hiện tại

    // Sắp xếp để hàng đợi ưu tiên chọn thời gian nhỏ nhất trước
    bool operator<(const State& other) const {
        return time > other.time;
    }
};

long long dijkstra(int n, int u, int v, int delta, const vector<vector<Edge>>& graph) {
    // Mảng lưu thời gian ngắn nhất tại mỗi nút, với từng tuyến đường
    vector<vector<long long>> dist(n + 1, vector<long long>(101, INF));
    priority_queue<State> pq;

    // Khởi tạo tại ga u
    for (int line = 0; line <= 100; ++line) {
        dist[u][line] = 0;
    }
    pq.push({u, 0, -1}); // -1 là tuyến đường khởi đầu chưa xác định

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        int node = current.node;
        long long time = current.time;
        int line = current.line;

        // Nếu đã đến đích, trả về thời gian
        if (node == v) return time;

        // Duyệt các cạnh kề
        for (const Edge& edge : graph[node]) {
            long long newTime = time + edge.time;

            // Tính thêm chi phí nếu chuyển tuyến
            if (line != -1 && line != edge.line) {
                newTime += line * delta + edge.line;
            }

            // Cập nhật nếu tìm thấy thời gian ngắn hơn
            if (newTime < dist[edge.to][edge.line]) {
                dist[edge.to][edge.line] = newTime;
                pq.push({edge.to, newTime, edge.line});
            }
        }
    }

    // Không tìm thấy đường đi
    return -1;
}

int main() {
    ifstream input("METRO.INP");
    ofstream output("METRO.OUT");

    // Kiểm tra mở file
    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n, m, u, v, delta;
    input >> n >> m >> u >> v >> delta;

    vector<vector<Edge>> graph(n + 1);

    // Đọc dữ liệu các tuyến đường
    for (int i = 0; i < m; ++i) {
        int uk, vk, tk, line;
        input >> uk >> vk >> tk >> line;

        // Thêm cạnh hai chiều vào đồ thị
        graph[uk].push_back({vk, tk, line});
        graph[vk].push_back({uk, tk, line});
    }

    // Tìm thời gian ngắn nhất
    long long result = dijkstra(n, u, v, delta, graph);

    // Ghi kết quả ra file
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
