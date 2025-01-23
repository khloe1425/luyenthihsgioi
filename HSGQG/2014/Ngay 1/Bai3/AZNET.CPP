#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc để lưu cạnh
struct Edge {
    int u, v, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

// Hàm tìm cha (Union-Find)
int findParent(vector<int>& parent, int u) {
    if (parent[u] != u) {
        parent[u] = findParent(parent, parent[u]);
    }
    return parent[u];
}

// Hàm hợp nhất hai tập (Union-Find)
void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int kruskal(int n, vector<Edge>& edges) {
    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end());

    int mstCost = 0, edgeCount = 0;

    for (const auto& edge : edges) {
        if (findParent(parent, edge.u) != findParent(parent, edge.v)) {
            unionSets(parent, rank, edge.u, edge.v);
            mstCost += edge.cost;
            edgeCount++;
            if (edgeCount == n - 1) break;
        }
    }

    if (edgeCount < n - 1) return -1;

    return mstCost;
}

int main() {
    ifstream fin("AZNET.INP");
    ofstream fout("AZNET.OUT");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int T;
    fin >> T;

    while (T--) {
        int n, m;
        fin >> n >> m;

        vector<Edge> edges(m);
        for (int i = 0; i < m; ++i) {
            fin >> edges[i].u >> edges[i].v >> edges[i].cost;
        }

        int result = kruskal(n, edges);
        fout << result << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
