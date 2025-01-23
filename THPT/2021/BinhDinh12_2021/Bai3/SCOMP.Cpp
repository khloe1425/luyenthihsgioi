#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

using namespace std;

const int MAXN = 100005;
vector<int> tree[MAXN]; // Cây công ty biểu diễn dưới dạng danh sách kề
int skill[MAXN];        // Khả năng lập trình của từng nhân viên
int subtree_sum[MAXN];  // Tổng kỹ năng trong cây con
bool visited[MAXN];     // Đánh dấu đã thăm trong DFS

// Hàm DFS để tính tổng kỹ năng trong cây con
void dfs(int u) {
    visited[u] = true;
    subtree_sum[u] = skill[u];
    for (int v : tree[u]) {
        if (!visited[v]) {
            dfs(v);
            subtree_sum[u] += subtree_sum[v];
        }
    }
}

int main() {
    ifstream input("SCOMP.INP");
    ofstream output("SCOMP.OUT");

    int n, m;
    input >> n >> m;

    // Đọc kỹ năng của từng nhân viên
    for (int i = 1; i <= n; ++i) {
        input >> skill[i];
    }

    // Xây dựng danh sách kề
    for (int i = 1; i < n; ++i) {
        int u, v;
        input >> u >> v;
        tree[v].push_back(u); // Nhân viên v là cấp trên trực tiếp của u
    }

    // Khởi tạo
    memset(visited, false, sizeof(visited));
    dfs(1); // DFS bắt đầu từ giám đốc công ty (nhân viên 1)

    // Xử lý các truy vấn
    for (int i = 0; i < m; ++i) {
        string query_type;
        input >> query_type;
        if (query_type == "Q") {
            int a;
            input >> a;
            output << subtree_sum[a] << endl;
        } else if (query_type == "U") {
            int a, x;
            input >> a >> x;
            int diff = x - skill[a];
            skill[a] = x;

            // Cập nhật lại giá trị tổng trong cây con
            for (int v = a; v != 0; v = 0) { // Chỉ duyệt từ a ngược lên
                subtree_sum[v] += diff;
            }
        }
    }

    input.close();
    output.close();
    return 0;
}
