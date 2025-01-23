#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// Cấu trúc trạng thái khối hộp
struct State {
    int x, y, orientation; // Vị trí (x, y) và hướng
    vector<pair<int, int>> activeCells; // Các ô chiếm bởi khối hộp

    bool operator<(const State &other) const {
        return tie(x, y, orientation, activeCells) < tie(other.x, other.y, other.orientation, other.activeCells);
    }
};

// Hướng di chuyển: lên, xuống, trái, phải
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// Hàm kiểm tra trạng thái hợp lệ
bool isValid(const vector<pair<int, int>> &cells, int m, int n, const set<pair<int, int>> &red) {
    for (auto cell : cells) {
        if (cell.first < 1 || cell.first > m || cell.second < 1 || cell.second > n) {
            return false;
        }
        if (red.find(cell) != red.end()) {
            return false;
        }
    }
    return true;
}

// Hàm sinh trạng thái mới sau thao tác
vector<pair<int, int>> moveCells(const vector<pair<int, int>> &cells, int dx, int dy) {
    vector<pair<int, int>> newCells;
    for (auto cell : cells) {
        newCells.push_back({cell.first + dx, cell.second + dy});
    }
    return newCells;
}

// BFS để tìm số ô sáng nhiều nhất
int solve(int a, int b, int c, int m, int n, const set<pair<int, int>> &red) {
    set<State> visited;
    queue<State> q;

    // Trạng thái khởi tạo
    State initial = {1, 1, 0, {{1, 1}}};
    q.push(initial);
    visited.insert(initial);

    int maxActivated = 0;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // Cập nhật số ô sáng nhiều nhất
        maxActivated = max(maxActivated, (int)current.activeCells.size());

        // Thử các thao tác
        for (int dir = 0; dir < 4; dir++) {
            vector<pair<int, int>> newCells = moveCells(current.activeCells, dx[dir], dy[dir]);
            if (!isValid(newCells, m, n, red)) continue;

            State newState = {current.x + dx[dir], current.y + dy[dir], dir, newCells};
            if (visited.find(newState) == visited.end()) {
                q.push(newState);
                visited.insert(newState);
            }
        }
    }

    return maxActivated;
}

int main() {
    // Đọc dữ liệu từ file
    freopen("BLGAME.INP", "r", stdin);
    freopen("BLGAME.OUT", "w", stdout);

    int a, b, c, m, n, k;
    cin >> a >> b >> c >> m >> n >> k;

    set<pair<int, int>> red;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        red.insert({x, y});
    }

    cout << solve(a, b, c, m, n, red) << endl;

    return 0;
}
