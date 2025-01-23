#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> graph[MAXN]; // Danh sách kề (đồ thị)
vector<pair<int, int>> bridges;    // Danh sách các cầu
vector<int> tin, low;             // Thời gian vào và giá trị low-link
vector<bool> visited;
int timer;

// Hàm DFS tìm cầu
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (auto edge : graph[v]) {
        int to = edge.first;
        if (to == p) continue; // Bỏ qua cạnh đến nút cha
        if (visited[to]) {
            // Cạnh ngược
            low[v] = min(low[v], tin[to]);
        } else {
            // Cạnh tiến
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.emplace_back(min(v, to), max(v, to));
            }
        }
    }
}

bool is_bridge(int u, int v) {
    return binary_search(bridges.begin(), bridges.end(), make_pair(min(u, v), max(u, v)));
}

int main() {
    ifstream fin("COMNET.INP");
    ofstream fout("COMNET.OUT");

    int t;
    fin >> t;
    while (t--) {
        int n, m, q;
        fin >> n >> m >> q;

        // Reset dữ liệu
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }
        bridges.clear();
        tin.assign(n + 1, -1);
        low.assign(n + 1, -1);
        visited.assign(n + 1, false);
        timer = 0;

        // Đọc m cạnh
        for (int i = 0; i < m; i++) {
            int u, v;
            fin >> u >> v;
            graph[u].emplace_back(v, i);
            graph[v].emplace_back(u, i);
        }

        // Tìm các cầu
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        // Sắp xếp danh sách các cầu để tìm kiếm nhị phân
        sort(bridges.begin(), bridges.end());

        // Kiểm tra q đường truyền mới
        while (q--) {
            int u, v;
            fin >> u >> v;
            if (is_bridge(u, v)) {
                fout << "NO" << endl;
            } else {
                fout << "YES" << endl;
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}
