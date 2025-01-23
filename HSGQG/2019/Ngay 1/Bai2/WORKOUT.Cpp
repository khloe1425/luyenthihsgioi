#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>
using namespace std;

struct Edge {
    int to, weight;
};

// Dijkstra's algorithm to find shortest paths from source
vector<int> dijkstra(int n, int source, const vector<vector<Edge>> &graph) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto &edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ifstream inputFile("WORKOUT.INP");
    ofstream outputFile("WORKOUT.OUT");

    int N, M, K;
    inputFile >> N >> M >> K;

    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        inputFile >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // Đọc điểm xuất phát và điểm đích của Nam
    int namStart, namEnd;
    inputFile >> namStart >> namEnd;

    // Đọc điểm xuất phát và điểm đích của bạn bè
    vector<int> p(K), start(K), end(K);
    for (int i = 0; i < K; ++i) {
        inputFile >> p[i] >> start[i] >> end[i];
    }

    // Tìm đường đi ngắn nhất từ tất cả các điểm
    auto distFromNamStart = dijkstra(N, namStart, graph);
    auto distFromNamEnd = dijkstra(N, namEnd, graph);

    // Tính thời gian Nam cần để đến đích
    int namTime = distFromNamStart[namEnd];

    int S = 0; // Giá trị lớn nhất của khoảng cách chênh lệch
    for (int i = 0; i < K; ++i) {
        int friendStart = start[i];
        int friendEnd = end[i];

        int friendTime = distFromNamStart[friendStart] + distFromNamEnd[friendEnd];
        if (friendTime > namTime) {
            S = max(S, friendTime - namTime);
        }
    }

    outputFile << S << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
