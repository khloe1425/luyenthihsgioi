#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Định nghĩa hướng di chuyển (lên, phải, xuống, trái)
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    ifstream fin("ROBOT.INP");
    ofstream fout("ROBOT.OUT");

    int N, x, y, S;
    fin >> N >> x >> y >> S;

    vector<string> maze(N);
    for (int i = 0; i < N; i++) {
        fin >> maze[i];
    }

    // Chuyển tọa độ (x, y) về chỉ số mảng (0-based)
    x -= 1;
    y -= 1;

    int direction = 0; // Hướng ban đầu: lên

    // Mô phỏng S giây
    while (S--) {
        int nx = x + dx[direction];
        int ny = y + dy[direction];

        // Nếu không gặp vật cản và trong biên, di chuyển
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && maze[nx][ny] == '.') {
            x = nx;
            y = ny;
        } else {
            // Nếu gặp vật cản, quay trái 90°
            direction = (direction + 1) % 4;
        }
    }

    // Chuyển kết quả tọa độ về dạng (1-based)
    fout << (x + 1) << " " << (y + 1) << endl;

    fin.close();
    fout.close();

    return 0;
}
