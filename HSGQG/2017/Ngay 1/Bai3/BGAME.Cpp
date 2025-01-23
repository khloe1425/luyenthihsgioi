#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int to;      // Nút đích
    int weight;  // Trọng số của cạnh
};

// Hàm tính điểm tối ưu
int calculateScore(int minScore, int maxScore) {
    return minScore + maxScore;
}

// Thuật toán Dijkstra tìm điểm tối ưu nhất
int findMaxScore(int n, const vector<vector<Edge>>& graph) {
    vector<int> dist(n + 1, -1); // Điểm cao nhất tại mỗi nút (khởi tạo là -1)
    priority_queue<pair<int, int>> pq; // (điểm, nút hiện tại), lưu âm điểm để ưu tiên lớn nhất

    // Khởi tạo tại nút 1
    dist[1] = INT_MAX; // Điểm tối đa
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        int currentScore = pq.top().first; // Điểm hiện tại
        int currentNode = pq.top().second; // Nút hiện tại
        pq.pop();

        // Kiểm tra các cạnh kề
        for (const Edge& edge : graph[currentNode]) {
            int nextNode = edge.to;
            int weight = edge.weight;

            // Tính điểm mới
            int newScore = calculateScore(min(dist[currentNode], weight), weight);

            // Nếu điểm mới lớn hơn điểm hiện tại của nút đích, cập nhật
            if (newScore > dist[nextNode]) {
                dist[nextNode] = newScore;
                pq.push({newScore, nextNode});
            }
        }
    }

    // Trả về điểm tối ưu tại nút n hoặc 0 nếu không có đường đi
    return dist[n] == -1 ? 0 : dist[n];
}

int main() {
    ifstream input("BGAME.INP");
    ofstream output("BGAME.OUT");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở file BGAME.INP hoặc BGAME.OUT!" << endl;
        return 1;
    }

    int n, m;
    input >> n >> m;

    vector<vector<Edge>> graph(n + 1);

    // Đọc dữ liệu đầu vào
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        input >> u >> v >> w;

        // Bỏ qua các cạnh không hợp lệ
        if (u != v && w > 0) {
            graph[u].push_back({v, w});
            graph[v].push_back({u, w}); // Đồ thị vô hướng
        }
    }

    // Tìm điểm tối ưu
    int result = findMaxScore(n, graph);

    // Ghi kết quả ra file
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
