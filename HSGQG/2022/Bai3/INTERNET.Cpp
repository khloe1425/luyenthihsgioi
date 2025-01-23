#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <set>

using namespace std;

// Struct để lưu thông tin cạnh
struct Edge {
    int u, v, weight;
};

// So sánh cạnh theo trọng số
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Tìm tập hợp của một đỉnh (Union-Find)
int findSet(int u, vector<int>& parent) {
    if (u != parent[u]) {
        parent[u] = findSet(parent[u], parent); // Path compression
    }
    return parent[u];
}

// Hợp nhất hai tập hợp
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findSet(u, parent);
    v = findSet(v, parent);
    if (u != v) {
        if (rank[u] > rank[v]) {
            parent[v] = u;
        } else if (rank[u] < rank[v]) {
            parent[u] = v;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int main() {
    ifstream input("INTERNET.INP");
    ofstream output("INTERNET.OUT");

    int n, s, k;
    input >> n >> s >> k;

    vector<pair<int, int>> coordinates(n);
    for (int i = 0; i < n; i++) {
        input >> coordinates[i].first >> coordinates[i].second;
    }

    vector<Edge> edges;

    // Tạo danh sách các cạnh dựa trên khoảng cách
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int distance = abs(coordinates[i].first - coordinates[j].first) +
                           abs(coordinates[i].second - coordinates[j].second);
            if (distance <= s) {
                edges.push_back({i, j, distance});
            }
        }
    }

    // Sắp xếp cạnh theo trọng số
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int total_cost = 0;
    int groups = n;

    // Kruskal's algorithm để ghép nhóm liên thông
    for (Edge e : edges) {
        if (findSet(e.u, parent) != findSet(e.v, parent)) {
            unionSet(e.u, e.v, parent, rank);
            total_cost += e.weight;
            groups--;
        }
    }

    // Nếu số nhóm > 1, thêm tối đa k cạnh để nối các nhóm
    if (groups > 1) {
        vector<Edge> additional_edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int distance = abs(coordinates[i].first - coordinates[j].first) +
                               abs(coordinates[i].second - coordinates[j].second);
                additional_edges.push_back({i, j, distance});
            }
        }

        sort(additional_edges.begin(), additional_edges.end(), compareEdges);

        for (Edge e : additional_edges) {
            if (findSet(e.u, parent) != findSet(e.v, parent) && k > 0) {
                unionSet(e.u, e.v, parent, rank);
                total_cost += e.weight;
                k--;
                groups--;
                if (groups == 1) break;
            }
        }
    }

    output << total_cost << endl;

    input.close();
    output.close();

    return 0;
}
