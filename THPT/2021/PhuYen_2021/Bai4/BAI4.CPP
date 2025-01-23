#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;          // Giới hạn số đỉnh
const int INF = 1e9 + 7;       // Vô cùng lớn

vector<pair<int, int>> adj[MAXN]; // Danh sách kề: {đỉnh kề, trọng số}
int dist[MAXN];                  // Mảng lưu khoảng cách ngắn nhất
int parent[MAXN];                // Mảng lưu cha của mỗi đỉnh
int n, m, start, end_point;

// Hàm Dijkstra tìm đường đi ngắn nhất
void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + MAXN, INF);
    memset(parent, -1, sizeof(parent));

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u; // Ghi nhận đỉnh cha
                pq.push({dist[v], v});
            }
        }
    }
}

// Hàm truy vết đường đi
vector<int> getPath(int start, int end_point) {
    vector<int> path;
    for (int u = end_point; u != -1; u = parent[u]) {
        path.push_back(u);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("BAI4.INP");
    ofstream fout("BAI4.OUT");

    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        fin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c}); // Đồ thị vô hướng
    }
    fin >> start >> end_point;

    // Tìm đường đi ngắn nhất từ start đến end_point
    dijkstra(start);

    // Ghi ra chiều dài đường đi ngắn nhất
    fout << dist[end_point] << "\n";

    // Truy vết và ghi ra đường đi
    vector<int> path = getPath(start, end_point);
    for (int u : path) {
        fout << u << " ";
    }
    fout << "\n";

    fin.close();
    fout.close();
    return 0;
}
