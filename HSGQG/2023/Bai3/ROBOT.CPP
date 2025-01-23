#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Hướng di chuyển: trên, dưới, trái, phải
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int W, L, N, Q;
set<pair<int, int>> chargingStations;

// BFS để tính khoảng cách tối thiểu từ các trạm sạc đến toàn bộ lưới
int calculateMinimumEnergy() {
    queue<pair<int, int>> q;
    map<pair<int, int>, int> distance;

    // Khởi tạo khoảng cách cho tất cả các ô
    for (auto station : chargingStations) {
        q.push(station);
        distance[station] = 0;
    }

    int maxEnergy = 0;

    // Thực hiện BFS
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Cập nhật khoảng cách tối đa
        maxEnergy = max(maxEnergy, distance[{x, y}]);

        // Duyệt các ô xung quanh
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Nếu nằm trong lưới và chưa được tính khoảng cách
            if (nx >= 1 && nx <= W && ny >= 1 && ny <= L && distance.find({nx, ny}) == distance.end()) {
                distance[{nx, ny}] = distance[{x, y}] + 1;
                q.push({nx, ny});
            }
        }
    }

    return maxEnergy;
}

int main() {
    ifstream inputFile("ROBOT.INP");
    ofstream outputFile("ROBOT.OUT");

    inputFile >> W >> L >> N >> Q;

    // Đọc danh sách trạm sạc ban đầu
    for (int i = 0; i < N; ++i) {
        int r, c;
        inputFile >> r >> c;
        chargingStations.insert({r, c});
    }

    // Ghi năng lượng tối thiểu ban đầu
    outputFile << calculateMinimumEnergy() << endl;

    // Xử lý truy vấn
    for (int i = 0; i < Q; ++i) {
        char type;
        int r, c;
        inputFile >> type >> r >> c;

        if (type == '+') {
            // Thêm trạm sạc
            chargingStations.insert({r, c});
        } else if (type == '-') {
            // Xóa trạm sạc
            chargingStations.erase({r, c});
        }

        // Ghi năng lượng tối thiểu sau truy vấn
        outputFile << calculateMinimumEnergy() << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
