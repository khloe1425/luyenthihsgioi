#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 20005;

vector<int> adj[MAXN]; // Danh sách kề
bool visited[MAXN];

// Hàm DFS để duyệt tìm cụm kết nối
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int countComponents(int n, int exclude) {
    memset(visited, false, sizeof(visited)); // Đặt lại mảng visited
    visited[exclude] = true; // Xóa đỉnh exclude
    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i); // Duyệt cụm kết nối từ đỉnh i
        }
    }
    return components;
}

int main() {
    ifstream input("CKN.INP");
    ofstream output("CKN.OUT");

    int n, m;
    input >> n >> m;

    // Đọc danh sách kề
    for (int i = 0; i < m; i++) {
        int u, v;
        input >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Tính số cụm kết nối khi xóa từng đỉnh
    for (int i = 1; i <= n; i++) {
        output << countComponents(n, i) << endl;
    }

    input.close();
    output.close();

    return 0;
}
