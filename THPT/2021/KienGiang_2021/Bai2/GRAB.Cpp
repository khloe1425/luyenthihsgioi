#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100; 
vector<int> adj[MAXN + 5]; // Danh sách kề
int match[MAXN + 5];       // Đỉnh được nối với đỉnh v
bool visited[MAXN + 5];
int N;

// DFS tìm đường tăng luồng
bool dfs(int u) {
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("GRAB.INP");
    ofstream fout("GRAB.OUT");

    fin >> N; // Số lượng đơn hàng và thành viên
    for (int i = 0; i < N; ++i) {
        int u, v;
        fin >> u >> v; // Đọc cặp đơn hàng u và thành viên v
        adj[u].push_back(v);
    }

    memset(match, -1, sizeof(match)); // Khởi tạo các đỉnh chưa được nối
    int maxMatches = 0;

    // Tìm đường tăng luồng
    for (int i = 1; i <= N; ++i) {
        memset(visited, false, sizeof(visited));
        if (dfs(i))
            maxMatches++;
    }

    fout << maxMatches << "\n";
    // Ghi ra kết quả ghép đôi theo yêu cầu
    for (int v = 1; v <= N; ++v) {
        if (match[v] != -1) {
            fout << match[v] << " " << v << "\n";
        }
    }

    fin.close();
    fout.close();
    return 0;
}
