#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, weight;
};

void dijkstra(int start, const vector<vector<Edge>>& graph, vector<int>& distances) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distances[node]) continue;

        for (const Edge& edge : graph[node]) {
            int nextNode = edge.to;
            int nextDist = dist + edge.weight;
            if (nextDist < distances[nextNode]) {
                distances[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }
}

int main() {
    ifstream input("DANCE.INP");
    ofstream output("DANCE.OUT");

    int n, m, k;
    input >> n >> m >> k;

    vector<vector<Edge>> graph(n + 1);
    vector<int> members(k);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        input >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 0; i < k; ++i) {
        input >> members[i];
    }

    vector<int> result(k);

    for (int i = 0; i < k; ++i) {
        vector<int> distances(n + 1, INF);
        dijkstra(members[i], graph, distances);

        int nearest = -1;
        int minDist = INF;

        for (int j = 0; j < k; ++j) {
            if (i != j && distances[members[j]] < minDist) {
                minDist = distances[members[j]];
                nearest = j;
            } else if (i != j && distances[members[j]] == minDist && members[j] < members[nearest]) {
                nearest = j;
            }
        }

        result[i] = members[nearest];
    }

    for (int i = 0; i < k; ++i) {
        output << result[i] << " ";
    }

    input.close();
    output.close();

    return 0;
}
