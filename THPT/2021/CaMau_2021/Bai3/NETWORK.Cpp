#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    // Đọc file input
    ifstream input("NETWORK.INP");
    ofstream output("NETWORK.OUT");

    int N, M;
    input >> N >> M;

    vector<vector<int>> adj(N + 1); // Danh sách kề
    vector<bool> visited(N + 1, false); // Mảng đánh dấu đã thăm

    // Đọc các cạnh
    for (int i = 0; i < M; ++i) {
        int u, v;
        input >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Đồ thị vô hướng
    }

    int components = 0; // Số thành phần liên thông

    // Tìm các thành phần liên thông
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }

    // Ghi kết quả ra file
    output << components << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
