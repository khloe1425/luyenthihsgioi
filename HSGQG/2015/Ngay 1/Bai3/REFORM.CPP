#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
int n, m;

// Hàm DFS kiểm tra liên thông
void dfs(int node, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}

bool isConnected() {
    vector<bool> visited(n + 1, false);
    dfs(1, visited); // Bắt đầu từ đỉnh 1
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

int main() {
    ifstream input("REFORM.INP");
    ofstream output("REFORM.OUT");

    input >> n >> m;

    graph.assign(n + 1, vector<int>());
    set<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        input >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.insert({min(u, v), max(u, v)});
    }

    if (!isConnected()) {
        output << 0 << endl;
        return 0;
    }

    int count = 0;

    // Thử loại bỏ từng cạnh
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        // Loại bỏ cạnh (u, v)
        graph[u].erase(remove(graph[u].begin(), graph[u].end(), v), graph[u].end());
        graph[v].erase(remove(graph[v].begin(), graph[v].end(), u), graph[v].end());

        if (isConnected()) count++;

        // Khôi phục cạnh (u, v)
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Thử thêm từng cạnh
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (edges.count({i, j}) || edges.count({j, i})) continue;

            // Thêm cạnh (i, j)
            graph[i].push_back(j);
            graph[j].push_back(i);

            if (isConnected()) count++;

            // Xóa cạnh (i, j)
            graph[i].pop_back();
            graph[j].pop_back();
        }
    }

    output << count << endl;

    input.close();
    output.close();

    return 0;
}
