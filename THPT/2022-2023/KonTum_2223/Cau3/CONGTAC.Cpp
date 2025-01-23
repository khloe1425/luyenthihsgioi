#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <bitset>
using namespace std;

// Hàm chuyển đổi trạng thái bóng đèn khi bật một công tắc
int toggle(int state, int n, int k) {
    // Bật công tắc k, ảnh hưởng đến bóng đèn k-1, k, k+1
    if (k > 1) state ^= (1 << (k - 2)); // Bóng đèn k-1
    state ^= (1 << (k - 1));           // Bóng đèn k
    if (k < n) state ^= (1 << k);      // Bóng đèn k+1
    return state;
}

// BFS để tìm đường chuyển đổi trạng thái
string findMinSwitches(int n, int start, int goal) {
    queue<pair<int, int>> q; // pair<state, số bước>
    unordered_map<int, int> visited; // Lưu trạng thái đã duyệt và công tắc đã dùng
    unordered_map<int, int> previous; // Để lần theo công tắc đã bật
    unordered_map<int, int> usedSwitch; // Công tắc đã dùng để đạt đến trạng thái hiện tại

    q.push({start, 0});
    visited[start] = -1;

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        // Nếu đạt trạng thái đích, xây dựng kết quả
        if (current == goal) {
            int state = current;
            int switches = 0;
            while (state != start) {
                int switchUsed = usedSwitch[state];
                switches |= (1 << (switchUsed - 1));
                state = previous[state];
            }
            return to_string(switches);
        }

        // Thử bật các công tắc
        for (int k = 1; k <= n; ++k) {
            int next = toggle(current, n, k);
            if (visited.find(next) == visited.end()) {
                visited[next] = current;
                previous[next] = current;
                usedSwitch[next] = k;
                q.push({next, steps + 1});
            }
        }
    }

    return "Khong"; // Không thể đạt trạng thái đích
}

int main() {
    ifstream inputFile("CONGTAC.INP");
    ofstream outputFile("CONGTAC.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int testIndex = 0;
    int n = 5; // Số bóng đèn (N cố định trong bài)
    int start, goal;

    while (inputFile >> start >> goal) {
        ++testIndex;

        // Chuyển trạng thái từ số nguyên sang bitmask
        int startState = start;
        int goalState = goal;

        string result = findMinSwitches(n, startState, goalState);
        outputFile << testIndex << " " << result << endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
