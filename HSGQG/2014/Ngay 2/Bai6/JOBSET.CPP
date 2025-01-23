#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// Hàm thực hiện Topological Sorting và kiểm tra chu trình
bool topologicalSort(int n, vector<vector<int>>& graph, vector<int>& order) {
    vector<int> inDegree(n + 1, 0);

    // Tính bậc vào của các đỉnh
    for (int u = 1; u <= n; ++u) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }

    // Sử dụng hàng đợi để duyệt các đỉnh có bậc vào bằng 0
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Nếu số đỉnh trong thứ tự khác số đỉnh ban đầu, đồ thị có chu trình
    return (order.size() == n);
}

int main() {
    ifstream fin("JOBSET.INP");
    ofstream fout("JOBSET.OUT");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int n, m;
    fin >> n;

    vector<int> profit(n + 1);
    for (int i = 1; i <= n; ++i) {
        fin >> profit[i];
    }

    fin >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        graph[u].push_back(v);
    }

    // Topological Sorting để kiểm tra chu trình và duyệt thứ tự
    vector<int> order;
    if (!topologicalSort(n, graph, order)) {
        fout << 0 << endl; // Không thể thực hiện dự án nào
        return 0;
    }

    // Dynamic Programming để tính lợi nhuận tối đa
    vector<int> dp(n + 1, INT_MIN); // dp[u] lưu lợi nhuận tối đa khi thực hiện từ u
    for (int u : order) {
        dp[u] = max(dp[u], profit[u]); // Bắt đầu từ chính dự án u
        for (int v : graph[u]) {
            dp[v] = max(dp[v], dp[u] + profit[v]); // Cập nhật lợi nhuận tối đa cho các dự án phụ thuộc
        }
    }

    // Tìm lợi nhuận tối đa
    int maxProfit = 0;
    for (int i = 1; i <= n; ++i) {
        maxProfit = max(maxProfit, dp[i]);
    }

    fout << maxProfit << endl;

    fin.close();
    fout.close();

    return 0;
}
