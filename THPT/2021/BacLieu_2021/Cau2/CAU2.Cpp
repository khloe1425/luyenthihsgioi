#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 5; // Giới hạn số lượng đỉnh
vector<int> adj[MAXN]; // Danh sách kề
int discovery_time[MAXN], low[MAXN]; // Thời gian vào và low-link value
bool visited[MAXN]; // Đánh dấu đỉnh đã thăm
int timer = 0; // Bộ đếm thời gian
int bridge_count = 0; // Số cầu

void dfs(int u, int parent) {
    visited[u] = true;
    discovery_time[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (v == parent) continue; // Bỏ qua đỉnh cha

        if (!visited[v]) {
            // DFS sâu hơn
            dfs(v, u);
            // Cập nhật low-link value
            low[u] = min(low[u], low[v]);

            // Kiểm tra điều kiện cầu
            if (low[v] > discovery_time[u]) {
                bridge_count++; // Phát hiện cầu
            }
        } else {
            // Nếu v đã thăm, cập nhật low-link value
            low[u] = min(low[u], discovery_time[v]);
        }
    }
}

int main() {
    // Đọc dữ liệu từ file
    ifstream input("CAU2.INP");
    ofstream output("CAU2.OUT");

    int N, M;
    input >> N >> M;

    // Xây dựng danh sách kề
    for (int i = 0; i < M; ++i) {
        int u, v;
        input >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Khởi tạo
    fill(visited, visited + N + 1, false);
    timer = 0;
    bridge_count = 0;

    // DFS từ tất cả các đỉnh (để đảm bảo đồ thị không liên thông vẫn đúng)
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    // Ghi kết quả ra file
    output << bridge_count << endl;

    // Đóng file
    input.close();
    output.close();

    return 0;
}
