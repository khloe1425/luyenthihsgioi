#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
using namespace std;

void assignIDs(int n, vector<vector<int>>& graph, vector<int>& ids) {
    vector<bool> visited(n + 1, false); // Đánh dấu đỉnh đã được gán nhãn
    priority_queue<int, vector<int>, greater<int>> pq; // Hàng đợi ưu tiên để xử lý các đỉnh theo thứ tự từ điển

    ids[1] = 1;           // Gán nhãn đầu tiên cho đỉnh 1
    visited[1] = true;    // Đánh dấu đỉnh 1 đã được gán nhãn
    pq.push(1);           // Đưa đỉnh 1 vào hàng đợi

    int currentID = 2;    // Nhãn tiếp theo cần gán

    while (!pq.empty()) {
        int u = pq.top(); // Lấy đỉnh có nhãn nhỏ nhất
        pq.pop();

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;  // Đánh dấu đỉnh v đã được gán nhãn
                ids[v] = currentID++; // Gán nhãn tiếp theo
                pq.push(v);         // Đưa đỉnh v vào hàng đợi
            }
        }
    }
}

int main() {
    ifstream input("IDCODE.INP");
    ofstream output("IDCODE.OUT");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n, m;
    input >> n >> m;

    vector<vector<int>> graph(n + 1); // Danh sách kề để biểu diễn đồ thị

    for (int i = 0; i < m; ++i) {
        int u, v;
        input >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Đồ thị vô hướng
    }

    // Sắp xếp danh sách kề để đảm bảo thứ tự từ điển
    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> ids(n + 1, 0); // Mảng lưu nhãn của các đỉnh
    assignIDs(n, graph, ids);

    // Ghi kết quả ra file
    for (int i = 1; i <= n; ++i) {
        output << ids[i] << " ";
    }
    output << endl;

    input.close();
    output.close();

    return 0;
}
