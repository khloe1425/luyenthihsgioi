#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    ifstream input("STABLE.INP");
    ofstream output("STABLE.OUT");

    int n, m, s;
    input >> n >> m >> s;

    vector<vector<int>> graph(n + 1);

    // Read the edges
    for (int i = 0; i < m; i++) {
        int u, v;
        input >> u >> v;
        graph[u].push_back(v);
    }

    // Distance and path count arrays
    vector<int> dist(n + 1, INF);
    vector<int> path_count(n + 1, 0);

    // BFS initialization
    queue<int> q;
    dist[s] = 0;
    path_count[s] = 1;
    q.push(s);

    // BFS traversal
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            // If this is the first time visiting the neighbor
            if (dist[neighbor] == INF) {
                dist[neighbor] = dist[current] + 1;
                path_count[neighbor] = path_count[current];
                q.push(neighbor);
            } else if (dist[neighbor] == dist[current] + 1) {
                // If we find another shortest path
                path_count[neighbor] += path_count[current];
            }
        }
    }

    // Debugging: Print distances and path counts
    for (int i = 1; i <= n; i++) {
        cout << "Node: " << i << ", Distance: " << dist[i] << ", Path Count: " << path_count[i] << endl;
    }

    // Count stable nodes
    int stable_count = 0;
    for (int i = 1; i <= n; i++) {
        if (i != s && dist[i] != INF && path_count[i] == 1) {
            stable_count++;
        }
    }

    // Write the result
    output << stable_count << endl;

    input.close();
    output.close();

    return 0;
}
