#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Hàm kiểm tra khả năng tô màu 2 nhóm
bool canColorTwoGroups(int n, const vector<vector<pair<int, int>>>& graph, vector<int>& group) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (group[i] == -1) {
            group[i] = 0; // Gán nhóm 0 cho đỉnh ban đầu
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto& edge : graph[u]) {
                    int v = edge.first;
                    if (group[v] == -1) {
                        group[v] = 1 - group[u]; // Gán nhóm đối lập
                        q.push(v);
                    } else if (group[v] == group[u]) {
                        return false; // Không thể chia nhóm
                    }
                }
            }
        }
    }
    return true;
}

// Hàm tính tổng thời gian thuyết phục tối thiểu
int calculateMinimumPersuasion(int n, const vector<vector<pair<int, int>>>& graph, const vector<vector<int>>& additionalEdges) {
    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first, weight = edge.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    int totalCost = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) return -1; // Không thể kết nối toàn bộ đồ thị
        totalCost += dist[i];
    }

    return totalCost;
}

int main() {
    ifstream fin("TEAMUP.INP");
    ofstream fout("TEAMUP.OUT");

    if (!fin || !fout) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int n, m;
    fin >> n;

    vector<int> p(n + 1), w(n + 1);
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 1; i <= n; i++) {
        fin >> p[i] >> w[i];
        graph[i].push_back({p[i], w[i]});
        graph[p[i]].push_back({i, w[i]});
    }

    fin >> m;
    vector<vector<int>> additionalEdges(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        fin >> additionalEdges[i][0] >> additionalEdges[i][1] >> additionalEdges[i][2];
    }

    vector<int> group(n + 1, -1);
    if (canColorTwoGroups(n, graph, group)) {
        fout << 0 << endl; // Không cần thuyết phục thêm
    } else {
        int minPersuasion = calculateMinimumPersuasion(n, graph, additionalEdges);
        fout << minPersuasion << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
