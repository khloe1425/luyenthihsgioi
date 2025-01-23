#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 100005;

vector<int> tree[MAXN]; // Cây phân cấp
int skills[MAXN];       // Năng lực của mỗi nhân viên
int subtreeSum[MAXN];   // Tổng năng lực của mỗi nhân viên và cấp dưới của họ
bool visited[MAXN];     // Đánh dấu nhân viên đã được duyệt

// Hàm DFS tính tổng năng lực của từng nhân viên
void dfs(int u) {
    visited[u] = true;
    subtreeSum[u] = skills[u];
    for (int v : tree[u]) {
        if (!visited[v]) {
            dfs(v);
            subtreeSum[u] += subtreeSum[v];
        }
    }
}

// Hàm cập nhật năng lực của nhân viên
void updateSkill(int u, int x) {
    int diff = x - skills[u];
    skills[u] = x;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        subtreeSum[current] += diff;
        for (int v : tree[current]) {
            q.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("SCOMP.INP", "r", stdin);
    freopen("SCOMP.OUT", "w", stdout);

    int n, m;
    cin >> n >> m;

    // Đọc năng lực ban đầu của nhân viên
    for (int i = 1; i <= n; i++) {
        cin >> skills[i];
    }

    // Đọc cây quan hệ lãnh đạo
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[v].push_back(u);
    }

    // Tính tổng năng lực ban đầu bằng DFS
    memset(visited, false, sizeof(visited));
    dfs(1);

    // Xử lý các truy vấn
    while (m--) {
        string query;
        cin >> query;
        if (query == "Q") {
            int a;
            cin >> a;
            cout << subtreeSum[a] << '\n';
        } else if (query == "U") {
            int a, x;
            cin >> a >> x;
            updateSkill(a, x);
        }
    }

    return 0;
}
