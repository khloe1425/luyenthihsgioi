#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>

using namespace std;

const int MAXN = 100005; // Giới hạn số lượng khu
const int INF = INT_MAX;

vector<pair<int, int>> adj[MAXN]; // Danh sách kề: adj[u] chứa (v, trọng số)

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n + 1, INF); // Khoảng cách từ start đến các đỉnh khác
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ifstream input("COVID.INP");
    ofstream output("COVID.OUT");

    int n, m;
    input >> n >> m;

    // Đọc các cạnh
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        input >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Xử lý các truy vấn
    for (int i = 0; i < m; ++i) {
        int s, d;
        input >> s >> d;

        vector<int> dist = dijkstra(s, n);
        output << dist[d] << endl;
    }

    input.close();
    output.close();

    return 0;
}
