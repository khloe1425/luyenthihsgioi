#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// Danh sách các phép biến đổi
vector<vector<int>> transformations = {
    {0, 1, 3, 4},    // Phép 1: ABDE
    {0, 1, 2},       // Phép 2: ABC
    {1, 2, 4, 5},    // Phép 3: BCEF
    {0, 3, 6},       // Phép 4: ADG
    {1, 3, 4, 5, 7}, // Phép 5: BDEFH
    {2, 5, 8},       // Phép 6: CFI
    {3, 4, 6, 7},    // Phép 7: DEGH
    {6, 7, 8},       // Phép 8: GHI
    {4, 5, 7, 8}     // Phép 9: EFHI
};

// Hàm áp dụng phép biến đổi lên trạng thái
string applyTransformation(const string &state, int transformation) {
    string newState = state;
    for (int i : transformations[transformation]) {
        newState[i] = (newState[i] - '0' + 1) % 4 + '0'; // Quay thêm 90 độ
    }
    return newState;
}

// BFS để tìm số lượng biến đổi tối thiểu
int bfs(const string &startState) {
    queue<pair<string, int>> q; // Trạng thái và số bước đã thực hiện
    unordered_map<string, bool> visited; // Đánh dấu trạng thái đã duyệt

    q.push({startState, 0});
    visited[startState] = true;

    while (!q.empty()) {
        auto [currentState, steps] = q.front();
        q.pop();

        // Kiểm tra nếu đạt trạng thái "000000000"
        if (currentState == "000000000") {
            return steps;
        }

        // Thử áp dụng tất cả các phép biến đổi
        for (int i = 0; i < 9; i++) {
            string nextState = applyTransformation(currentState, i);
            if (!visited[nextState]) {
                visited[nextState] = true;
                q.push({nextState, steps + 1});
            }
        }
    }

    return -1; // Không tìm thấy (trường hợp không thể xảy ra)
}

int main() {
    ifstream input("DONGHO.INP");
    ofstream output("DONGHO.OUT");

    string startState;
    input >> startState;

    int result = bfs(startState);
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
