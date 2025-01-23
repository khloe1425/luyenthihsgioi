#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>
using namespace std;

struct Edge {
    int to, weight, company;
};

struct Node {
    int stop, cost;
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

int main() {
    // Open input and output files
    ifstream inputFile("BUS.INP");
    ofstream outputFile("BUS.OUT");

    // Read input from file
    int n, m, s, t;
    inputFile >> n >> m >> s >> t;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int c, u, v, w;
        inputFile >> c >> u >> v >> w;
        graph[u].push_back({v, w, c});
        graph[v].push_back({u, w, c}); // Undirected graph
    }

    // Dijkstra's algorithm
    vector<int> cost(n + 1, INT_MAX);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    cost[s] = 0;
    pq.push({s, 0});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int currentStop = current.stop;
        int currentCost = current.cost;

        if (currentCost > cost[currentStop]) continue;

        for (const Edge &edge : graph[currentStop]) {
            int nextStop = edge.to;
            int nextCost = currentCost + edge.weight;

            if (nextCost < cost[nextStop]) {
                cost[nextStop] = nextCost;
                pq.push({nextStop, nextCost});
            }
        }
    }

    // Write output to file
    if (cost[t] == INT_MAX) {
        outputFile << -1 << endl;
    } else {
        outputFile << cost[t] << endl;
    }

    // Close files
    inputFile.close();
    outputFile.close();

    return 0;
}
