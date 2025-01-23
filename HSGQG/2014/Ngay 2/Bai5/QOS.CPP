#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int to, cost;
};

struct Node {
    int vertex, cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

void dijkstra(int n, int start, vector<vector<Edge>>& graph, vector<int>& dist, vector<int>& parent) {
    dist.assign(n + 1, INT_MAX);
    parent.assign(n + 1, -1);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.vertex;
        int currentCost = current.cost;

        if (currentCost > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int cost = edge.cost;

            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                parent[v] = u;
                pq.push({v, dist[v]});
            } else if (dist[u] + cost == dist[v] && u < parent[v]) {
                // Ưu tiên cha nhỏ hơn về thứ tự từ điển
                parent[v] = u;
            }
        }
    }
}

vector<int> reconstructPath(int start, int end, const vector<int>& parent) {
    vector<int> path;
    for (int at = end; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ifstream fin("QOS.INP");
    ofstream fout("QOS.OUT");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int n, m, t, k;
    fin >> n >> m >> t >> k;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        fin >> u >> v >> c;
        graph[u].push_back({v, c});
    }

    // Sắp xếp các cạnh trong danh sách kề theo thứ tự từ điển
    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end(), [](const Edge& a, const Edge& b) {
            return a.to < b.to;
        });
    }

    // Tìm độ trễ nhỏ nhất đến tất cả các nút
    vector<int> dist, parent;
    dijkstra(n, 1, graph, dist, parent);

    if (dist[t] == INT_MAX) {
        fout << -1 << endl; // Không có đường đi
    } else {
        int Tmin = dist[t];
        int Cmin = k;

        // Kiểm tra đường đi thỏa mãn QoS
        if (dist[t] > Tmin + Cmin) {
            fout << -1 << endl;
        } else {
            vector<int> path = reconstructPath(1, t, parent);
            fout << path.size() << endl;
            for (int node : path) {
                fout << node << " ";
            }
            fout << endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}
