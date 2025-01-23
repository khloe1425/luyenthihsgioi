#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

vector<int> adj[MAXN];
vector<pair<int, int>> edges;
bool visited[MAXN];
int parent[MAXN];
int n, m;

void dfs(int u, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<pair<int, int>> &criticalEdges, int &time) {
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v, visited, disc, low, parent, criticalEdges, time);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                criticalEdges.push_back({u, v});
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findCriticalEdges() {
    vector<bool> visited(n + 1, false);
    vector<int> disc(n + 1, -1), low(n + 1, -1), parent(n + 1, -1);
    vector<pair<int, int>> criticalEdges;
    int time = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, disc, low, parent, criticalEdges, time);
        }
    }

    if (criticalEdges.empty()) {
        cout << "-1\n";
    } else {
        cout << criticalEdges.size() << "\n";
        for (auto edge : criticalEdges) {
            cout << edge.first << " " << edge.second << "\n";
        }
    }
}

int main() {
    ifstream fin("CIRARC.INP");
    ofstream fout("CIRARC.OUT");

    fin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    vector<bool> visited(n + 1, false);
    vector<int> disc(n + 1, -1), low(n + 1, -1), parent(n + 1, -1);
    vector<pair<int, int>> criticalEdges;
    int time = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, disc, low, parent, criticalEdges, time);
        }
    }

    if (criticalEdges.empty()) {
        fout << "-1\n";
    } else {
        fout << criticalEdges.size() << "\n";
        for (auto edge : criticalEdges) {
            fout << edge.first << " " << edge.second << "\n";
        }
    }

    return 0;
}
