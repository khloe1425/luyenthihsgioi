#include <bits/stdc++.h>
using namespace std;

int bfs(int N, int P, int A, int B, int R) {
    queue<pair<int, int>> q; // (giá trị hiện tại, số bước)
    vector<bool> visited(P, false); // Đánh dấu các trạng thái đã thăm

    q.push({N, 0});
    visited[N] = true;

    while (!q.empty()) {
        int curr = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (curr == R) return steps; // Tìm thấy kết quả

        // Thực hiện 3 phép toán thay thế
        int next1 = (curr + A) % P;
        int next2 = (curr + B) % P;
        int next3 = (curr + A + B) % P;

        // Kiểm tra và đẩy các trạng thái mới vào hàng đợi
        if (!visited[next1]) {
            visited[next1] = true;
            q.push({next1, steps + 1});
        }
        if (!visited[next2]) {
            visited[next2] = true;
            q.push({next2, steps + 1});
        }
        if (!visited[next3]) {
            visited[next3] = true;
            q.push({next3, steps + 1});
        }
    }

    return -1; // Không tìm thấy kết quả
}

int main() {
    ifstream fin("THAYTHE.INP");
    ofstream fout("THAYTHE.OUT");

    int N, P, A, B, R;
    fin >> N >> P;
    fin >> A >> B >> R;

    int result = bfs(N, P, A, B, R);
    fout << result << "\n";

    fin.close();
    fout.close();
    return 0;
}
