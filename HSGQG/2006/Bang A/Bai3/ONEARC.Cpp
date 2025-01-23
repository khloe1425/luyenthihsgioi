#include <iostream>
#include <vector>
#include <algorithm> // Đảm bảo include thư viện này
#include <cstring>
using namespace std;

const int MAXN = 2005;

vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

bool isConnected(int n) {
    memset(visited, false, sizeof(visited));
    dfs(1); // Bắt đầu từ đỉnh 1
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

int main() {
    freopen("ONEARC.INP", "r", stdin);
    freopen("ONEARC.OUT", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    if (!isConnected(n)) {
        cout << "NO" << endl;
        return 0;
    }

    for (auto edge : edges) {
        int u = edge.first, v = edge.second;

        // Xóa cạnh u-v
        adj[u].erase(std::remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
        adj[v].erase(std::remove(adj[v].begin(), adj[v].end(), u), adj[v].end());

        if (!isConnected(n)) {
            cout << "YES" << endl;
            cout << u << " " << v << endl;
            return 0;
        }

        // Khôi phục cạnh u-v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "NO" << endl;
    return 0;
}
