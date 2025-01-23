#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Edge {
    int to, weight;
};

void dfs(int u, int parent, const vector<vector<Edge>> &graph, long long &totalCost) {
    for (const auto &edge : graph[u]) {
        int v = edge.to;
        int w = edge.weight;

        if (v != parent) {
            totalCost += 2 * w; // Đi và về
            dfs(v, u, graph, totalCost);
        }
    }
}

int main() {
    ifstream inputFile("VESINH.INP");
    ofstream outputFile("VESINH.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N, S;
    inputFile >> N >> S;

    vector<vector<Edge>> graph(N + 1);

    // Đọc các cạnh
    for (int i = 0; i < N - 1; ++i) {
        int A, B, C;
        inputFile >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    // Tổng chi phí di chuyển
    long long totalCost = 0;
    dfs(S, -1, graph, totalCost);

    // Ghi kết quả ra file
    outputFile << totalCost << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
