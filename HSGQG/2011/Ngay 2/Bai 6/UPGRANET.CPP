#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Edge {
    int u, v, w; // u, v là 2 đỉnh; w là trọng số
};

// Hàm tìm gốc của một đỉnh trong DSU (Disjoint Set Union)
int findRoot(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = findRoot(parent, parent[x]);
    }
    return parent[x];
}

// Hàm hợp nhất hai tập hợp trong DSU
bool unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = findRoot(parent, x);
    int rootY = findRoot(parent, y);
    if (rootX == rootY) return false;

    if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
    return true;
}

// Hàm kiểm tra nếu có thể tạo cây khung với ngưỡng T
bool isPossible(int n, vector<Edge>& edges, int T) {
    // Lọc các cạnh có trọng số >= T
    vector<Edge> filteredEdges;
    for (auto& edge : edges) {
        if (edge.w >= T) {
            filteredEdges.push_back(edge);
        }
    }

    // Sử dụng Kruskal để kiểm tra cây khung
    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; ++i) parent[i] = i;

    int components = n; // Số thành phần liên thông
    for (auto& edge : filteredEdges) {
        if (unionSets(parent, rank, edge.u, edge.v)) {
            components--; // Mỗi lần nối, giảm số thành phần liên thông
        }
    }

    return components == 1; // Nếu còn đúng 1 thành phần liên thông, cây khung hợp lệ
}

int main() {
    ifstream input("UPGRANET.INP");
    ofstream output("UPGRANET.OUT");

    int n, m;
    input >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        input >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    input.close();

    // Nhị phân trên ngưỡng T
    int left = 0, right = 1e6, bestT = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(n, edges, mid)) {
            bestT = mid;   // Lưu lại ngưỡng T khả thi
            left = mid + 1; // Tăng để tìm ngưỡng lớn hơn
        } else {
            right = mid - 1; // Giảm ngưỡng T
        }
    }

    // Tính chi phí nâng cấp để đạt ngưỡng T = bestT
    long long totalCost = 0;
    for (auto& edge : edges) {
        if (edge.w < bestT) {
            totalCost += (bestT - edge.w);
        }
    }

    // Ghi kết quả ra file
    output << totalCost << endl;
    output.close();

    return 0;
}
