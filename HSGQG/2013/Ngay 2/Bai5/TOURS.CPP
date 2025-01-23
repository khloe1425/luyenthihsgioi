#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 1e9;

int main() {
    ifstream fin("TOURS.INP");
    ofstream fout("TOURS.OUT");

    int T;
    fin >> T;

    while (T--) {
        int n, m;
        fin >> n >> m;

        // Khởi tạo ma trận khoảng cách
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
        for (int i = 1; i <= n; i++) {
            dist[i][i] = 0;
        }

        // Đọc các cạnh
        for (int i = 0; i < m; i++) {
            int u, v, c;
            fin >> u >> v >> c;
            dist[u][v] = min(dist[u][v], c); // Chọn cạnh có trọng số nhỏ nhất nếu có nhiều cạnh
        }

        // Floyd-Warshall để tính đường đi ngắn nhất
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Tính chi phí hành trình du lịch cho từng điểm
        for (int i = 1; i <= n; i++) {
            int min_cost = INF;

            for (int j = 1; j <= n; j++) {
                if (i != j && dist[i][j] < INF && dist[j][i] < INF) {
                    min_cost = min(min_cost, dist[i][j] + dist[j][i]);
                }
            }

            if (min_cost == INF) {
                fout << -1 << endl; // Không có chu trình
            } else {
                fout << min_cost << endl; // Chi phí tối thiểu
            }
        }
    }

    fin.close();
    fout.close();

    return 0;
}
