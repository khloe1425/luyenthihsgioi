#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct Region {
    int Q, W, C; // Sản lượng mỗi thửa ruộng, sản lượng cần thiết, chi phí
};

vector<int> graph[5005]; // Đồ thị kết nối giữa các vùng
bool visited[5005];

void dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

// Hàm kiểm tra tất cả các vùng có được kết nối với kinh đô hay không
bool isConnected(int N) {
    memset(visited, false, sizeof(visited));
    dfs(1); // Kinh đô là vùng 1
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) return false;
    }
    return true;
}

int main() {
    ifstream inputFile("FOOD.INP");
    ofstream outputFile("FOOD.OUT");

    int N, S;
    inputFile >> N >> S;

    vector<Region> regions(N + 1);

    for (int i = 1; i <= N; ++i) {
        inputFile >> regions[i].Q >> regions[i].W >> regions[i].C;
    }

    for (int i = 1; i < N; ++i) {
        int u, v;
        inputFile >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (!isConnected(N)) {
        outputFile << -1 << endl;
        return 0;
    }

    // Dynamic programming để tính tổng chi phí tối thiểu
    vector<ll> dp(S + 1, INF); // dp[x]: Chi phí tối thiểu để đạt sản lượng x
    dp[0] = 0;

    for (int i = 1; i <= N; ++i) {
        int Q = regions[i].Q, W = regions[i].W, C = regions[i].C;
        vector<ll> new_dp = dp;

        for (int x = 0; x <= S; ++x) {
            for (int k = 1; k <= W && x + k * Q <= S; ++k) {
                ll cost = 1LL * k * k * C;
                new_dp[x + k * Q] = min(new_dp[x + k * Q], dp[x] + cost);
            }
        }

        dp = new_dp;
    }

    // Kết quả: Tổng chi phí nhỏ nhất để đạt sản lượng >= S
    ll result = INF;
    for (int x = S; x <= S; ++x) {
        result = min(result, dp[x]);
    }

    if (result == INF) {
        outputFile << -1 << endl;
    } else {
        outputFile << result << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
