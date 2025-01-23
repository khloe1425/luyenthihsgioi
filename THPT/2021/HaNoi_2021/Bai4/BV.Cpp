#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

const int INF = INT_MAX;

void dijkstra(int start, int n, vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ifstream inputFile("BV.INP");
    ofstream outputFile("BV.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N, M, K;
    inputFile >> N >> M >> K;

    vector<vector<pair<int, int>>> graph(N + 1); // Đồ thị
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        inputFile >> u >> v;
        graph[u].push_back({v, 1});
        graph[v].push_back({u, 1});
    }

    vector<int> infected(M);
    for (int i = 0; i < M; ++i) {
        inputFile >> infected[i];
    }

    int result = 0;

    // Duyệt qua từng thành phố
    for (int i = 1; i <= N; ++i) {
        vector<int> dist(N + 1, INF);
        dijkstra(i, N, graph, dist);

        bool canBuild = true;
        for (int city : infected) {
            if (dist[city] > K) {
                canBuild = false;
                break;
            }
        }

        if (canBuild) {
            result++;
        }
    }

    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
