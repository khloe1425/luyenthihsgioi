#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN]; // Danh sách kề
bool visited[MAXN];    // Đánh dấu đỉnh đã thăm
int n, m;              // Số đỉnh và số cạnh
long long totalPaths = 0; // Tổng số đường đi

void dfs(int u, int start, int parent, int length) {
    for (int v : adj[u]) {
        if (v == start && length > 0) { // Quay lại đỉnh bắt đầu hợp lệ
            totalPaths++;
        } else if (!visited[v]) { // Nếu chưa thăm đỉnh v
            visited[v] = true;
            dfs(v, start, u, length + 1);
            visited[v] = false; // Backtracking
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ifstream fin("PARK.INP");
    ofstream fout("PARK.OUT");

    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited[1] = true; // Đánh dấu đỉnh bắt đầu
    dfs(1, 1, -1, 0); // Duyệt từ đỉnh 1, -1 là parent ban đầu

    fout << totalPaths / 6 << "\n"; 

    fin.close();
    fout.close();
    return 0;
}
