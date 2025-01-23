#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v;
    double weight;
};

double calculateDistance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

bool compareEdge(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

int findRoot(vector<int> &parent, int u) {
    if (u == parent[u]) return u;
    return parent[u] = findRoot(parent, parent[u]);
}

void unionSet(vector<int> &parent, vector<int> &rank, int u, int v) {
    u = findRoot(parent, u);
    v = findRoot(parent, v);
    if (u != v) {
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
}

int main() {
    ifstream fin("EFILL.INP");
    ofstream fout("EFILL.OUT");

    int N;
    fin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        fin >> points[i].first >> points[i].second;
    }

    int a, b;
    fin >> a >> b;
    a--, b--; 

    vector<Edge> edges;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if ((i == a && j == b) || (i == b && j == a)) continue; 
            edges.push_back({i, j, calculateDistance(points[i], points[j])});
        }
    }

    sort(edges.begin(), edges.end(), compareEdge);

    vector<int> parent(N), rank(N, 0);
    for (int i = 0; i < N; ++i) parent[i] = i;

    double totalWeight = 0;
    for (const auto &edge : edges) {
        if (findRoot(parent, edge.u) != findRoot(parent, edge.v)) {
            unionSet(parent, rank, edge.u, edge.v);
            totalWeight += edge.weight;
        }
    }

    fout << fixed << setprecision(2) << totalWeight << endl;
    fin.close();
    fout.close();

    return 0;
}
