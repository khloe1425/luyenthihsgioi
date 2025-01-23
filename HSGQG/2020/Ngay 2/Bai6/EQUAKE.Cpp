#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
using namespace std;

struct Edge {
    int to, weight;
};

int n, c;
vector<int> population;
vector<vector<Edge>> graph;
long long totalCost = 0;

// DFS để tính số nhân viên cần vận chuyển qua từng cạnh
int dfs(int node, int parent, int avg) {
    int extra = population[node] - avg; // Số nhân viên dư thừa hoặc thiếu
    for (const auto &edge : graph[node]) {
        if (edge.to != parent) {
            int transferred = dfs(edge.to, node, avg);
            extra += transferred; // Cập nhật số nhân viên dư thừa
            totalCost += 1LL * abs(transferred) * edge.weight;
        }
    }
    return extra;
}

int main() {
    // Đọc dữ liệu từ file
    ifstream inputFile("EQUAKE.INP");
    ofstream outputFile("EQUAKE.OUT");

    inputFile >> n >> c;
    population.resize(n + 1);
    graph.resize(n + 1);

    long long totalPopulation = 0;
    for (int i = 1; i <= n; ++i) {
        inputFile >> population[i];
        totalPopulation += population[i];
    }

    // Đọc các cạnh của đồ thị
    for (int i = 0; i < n - 1; ++i) {
        int u, v, d;
        inputFile >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    // Tính trung bình số nhân viên cứu hộ mỗi thành phố
    int avg = totalPopulation / n;

    // DFS để tính tổng chi phí vận chuyển
    dfs(1, -1, avg);

    // Ghi kết quả ra file
    outputFile << totalCost << endl;

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
