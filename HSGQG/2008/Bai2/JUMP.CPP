#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> memo;

// DFS with memoization to find the longest path
int dfs(int node) {
    if (memo[node] != -1) {
        return memo[node];
    }

    int max_length = 1; // At least the current node itself
    for (int neighbor : graph[node]) {
        max_length = max(max_length, 1 + dfs(neighbor));
    }

    memo[node] = max_length;
    return max_length;
}

int main() {
    ifstream input("JUMP.INP");
    ofstream output("JUMP.OUT");

    int n;
    input >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        input >> a[i];
    }

    // Build the graph
    graph.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue; // i and j must be distinct
            for (int k = 0; k < n; k++) {
                if (k != i && k != j && a[i] + a[j] == a[k]) {
                    graph[i].push_back(j); // Add directed edge from i to j
                    break; // Stop checking other values of k for this pair (i, j)
                }
            }
        }
    }

    // Perform DFS with memoization
    memo.assign(n, -1);
    int max_path = 0;
    for (int i = 0; i < n; i++) {
        max_path = max(max_path, dfs(i));
    }

    // Output the result
    output << max_path << endl;

    input.close();
    output.close();

    return 0;
}
