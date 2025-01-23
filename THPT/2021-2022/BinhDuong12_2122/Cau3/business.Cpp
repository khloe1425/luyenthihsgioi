#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int dfs(int node) {
    visited[node] = true;
    int count = 1; // Đếm ngôi làng hiện tại
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            count += dfs(neighbor);
        }
    }
    return count;
}

int main() {
    ifstream input("business.inp");
    ofstream output("business.out");

    int n, m;
    input >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        input >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxVillages = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            maxVillages = max(maxVillages, dfs(i));
        }
    }

    output << maxVillages << endl;

    input.close();
    output.close();
    return 0;
}
