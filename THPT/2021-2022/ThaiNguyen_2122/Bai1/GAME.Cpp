#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <tuple>

using namespace std;

const int dx[] = {1, -1, 0}; // Đi xuống, đi lên, đi ngang
const int dy[] = {0, 0, 1};  // Không đổi hàng, không đổi hàng, sang phải

struct State {
    int x, y, time, hold; // Dòng, cột, thời gian, thời gian giữ màn hình
};

int main() {
    ifstream input("GAME.INP");
    ofstream output("GAME.OUT");

    int N; // Số cột
    input >> N;

    vector<string> grid(10); // Lưới 10 dòng, N cột
    for (int i = 0; i < 10; i++) {
        input >> grid[i];
    }

    vector<vector<vector<int>>> visited(10, vector<vector<int>>(N, vector<int>(N + 1, 0))); // visited[x][y][hold]

    queue<State> q;
    q.push({0, 0, 0, 0});
    visited[0][0][0] = 1;

    vector<pair<int, int>> actions; // Lưu các thao tác (thời gian, giữ)

    while (!q.empty()) {
        auto [x, y, time, hold] = q.front();
        q.pop();

        if (y == N - 1) {
            output << actions.size() << endl;
            for (auto &[t, h] : actions) {
                output << t << " " << h << endl;
            }
            return 0;
        }

        for (int d = 0; d < 3; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < 10 && ny >= 0 && ny < N && grid[nx][ny] != 'X') {
                int nextHold = hold + 1;
                if (nextHold <= N && !visited[nx][ny][nextHold]) {
                    visited[nx][ny][nextHold] = 1;
                    q.push({nx, ny, time + 1, nextHold});

                    if (d == 2) {
                        actions.push_back({time + 1, nextHold});
                    }
                }
            }
        }
    }

    return 0;
}
