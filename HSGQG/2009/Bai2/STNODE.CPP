#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void bfs(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    ifstream input("STNODE.INP");
    ofstream output("STNODE.OUT");

    int n, m, s, t;
    input >> n >> m >> s >> t;

    vector<vector<int>> graph(n + 1);
    vector<vector<int>> reverse_graph(n + 1);

    // Read the edges
    for (int i = 0; i < m; i++) {
        int u, v;
        input >> u >> v;
        graph[u].push_back(v);
        reverse_graph[v].push_back(u);
    }

    // Step 1: BFS from s
    vector<bool> reachable_from_s(n + 1, false);
    bfs(s, graph, reachable_from_s);

    // Step 2: Reverse BFS from t
    vector<bool> can_reach_t(n + 1, false);
    bfs(t, reverse_graph, can_reach_t);

    // Step 3: Count st-crossroads
    int st_crossroads = 0;
    for (int i = 1; i <= n; i++) {
        if (i != s && i != t && reachable_from_s[i] && can_reach_t[i]) {
            st_crossroads++;
        }
    }

    // Output the result
    output << st_crossroads << endl;

    input.close();
    output.close();

    return 0;
}
