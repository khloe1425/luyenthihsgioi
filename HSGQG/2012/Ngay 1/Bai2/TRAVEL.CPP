#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

const int MAXN = 10001;

vector<int> adj[MAXN]; // Danh sách kề
bool visited[MAXN];    // Mảng đánh dấu các đỉnh đã thăm
int parent[MAXN];      // Mảng lưu cha để kiểm tra chu trình

// Hàm kiểm tra chu trình độ dài 4
bool findCycle4(int n, vector<int>& cycle) {
    for (int u = 1; u <= n; u++) {
        // Với mỗi đỉnh, duyệt tất cả các cặp đỉnh kề
        for (size_t i = 0; i < adj[u].size(); i++) {
            for (size_t j = i + 1; j < adj[u].size(); j++) {
                int v = adj[u][i];
                int w = adj[u][j];

                // Kiểm tra xem v và w có cạnh nối không
                if (find(adj[v].begin(), adj[v].end(), w) != adj[v].end()) {
                    cycle = {u, v, w, u};
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ifstream fin("TRAVEL.INP");
    ofstream fout("TRAVEL.OUT");

    int n, m;
    fin >> n >> m;

    // Đọc các cạnh
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> cycle;

    // Tìm chu trình độ dài 4
    if (findCycle4(n, cycle)) {
        for (int city : cycle) {
            fout << city << " ";
        }
        fout << endl;
    } else {
        fout << -1 << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
