#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_set>
#include <tuple>
using namespace std;

// Định nghĩa hàm băm cho std::tuple<int, int, int>
struct TupleHash {
    size_t operator()(const tuple<int, int, int>& t) const {
        size_t h1 = hash<int>()(get<0>(t));
        size_t h2 = hash<int>()(get<1>(t));
        size_t h3 = hash<int>()(get<2>(t));
        return h1 ^ (h2 << 1) ^ (h3 << 2); // Kết hợp các giá trị băm
    }
};

struct State {
    int a1, a2, a3; // Lượng nước trong các can
    int steps;      // Số lần rót nước

    bool operator<(const State& other) const {
        return tie(a1, a2, a3) < tie(other.a1, other.a2, other.a3);
    }
};

bool isTarget(const State& state, const vector<int>& target) {
    return state.a1 == target[0] && state.a2 == target[1] && state.a3 == target[2];
}

vector<State> getNextStates(const State& current, const vector<int>& capacities) {
    vector<State> nextStates;
    vector<int> amounts = {current.a1, current.a2, current.a3};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i != j && amounts[i] > 0) {
                // Tính lượng nước có thể rót từ can i sang can j
                int pourAmount = min(amounts[i], capacities[j] - amounts[j]);

                // Tạo trạng thái mới
                vector<int> newAmounts = amounts;
                newAmounts[i] -= pourAmount;
                newAmounts[j] += pourAmount;

                nextStates.push_back({newAmounts[0], newAmounts[1], newAmounts[2], current.steps + 1});
            }
        }
    }
    return nextStates;
}

int bfs(const vector<int>& capacities, const vector<int>& initial, const vector<int>& target) {
    unordered_set<tuple<int, int, int>, TupleHash> visited;
    queue<State> q;

    // Khởi tạo trạng thái ban đầu
    State start = {initial[0], initial[1], initial[2], 0};
    q.push(start);
    visited.insert(make_tuple(start.a1, start.a2, start.a3));

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // Kiểm tra xem đã đạt trạng thái đích chưa
        if (isTarget(current, target)) {
            return current.steps;
        }

        // Sinh các trạng thái tiếp theo
        vector<State> nextStates = getNextStates(current, capacities);
        for (const State& next : nextStates) {
            tuple<int, int, int> stateTuple = make_tuple(next.a1, next.a2, next.a3);
            if (visited.find(stateTuple) == visited.end()) {
                q.push(next);
                visited.insert(stateTuple);
            }
        }
    }

    // Nếu không tìm được đường đi
    return -1;
}

int main() {
    ifstream input("POUR.INP");
    ofstream output("POUR.OUT");

    vector<int> capacities(3), initial(3), target(3);

    // Đọc dữ liệu từ file
    for (int i = 0; i < 3; ++i) input >> capacities[i];
    for (int i = 0; i < 3; ++i) input >> initial[i];
    for (int i = 0; i < 3; ++i) input >> target[i];

    // Kiểm tra dữ liệu đầu vào hợp lệ
    for (int i = 0; i < 3; ++i) {
        if (initial[i] > capacities[i] || target[i] > capacities[i]) {
            output << -1 << endl;
            return 0;
        }
    }

    // Giải bài toán bằng BFS
    int result = bfs(capacities, initial, target);

    // Ghi kết quả ra file
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
