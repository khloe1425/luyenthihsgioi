#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// Kích thước bàn cờ
const int N = 8;

// Hướng di chuyển của các quân cờ
const int dx_queen[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy_queen[] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int dx_rook[] = {0, 0, -1, 1};
const int dy_rook[] = {-1, 1, 0, 0};

const int dx_bishop[] = {-1, -1, 1, 1};
const int dy_bishop[] = {-1, 1, -1, 1};

const int dx_knight[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy_knight[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Ô thưởng
struct Cell {
    int x, y, value;
};

int board[N][N];
vector<Cell> cells;

// Kiểm tra ô có nằm trong bàn cờ không
bool is_valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// Đánh dấu ô bị khống chế
void mark_control(int x, int y, const int dx[], const int dy[], int steps, bool controlled[N][N]) {
    for (int d = 0; d < steps; d++) {
        int nx = x, ny = y;
        while (true) {
            nx += dx[d];
            ny += dy[d];
            if (!is_valid(nx, ny)) break;
            controlled[nx][ny] = true;
            // Nếu là quân Ngựa, chỉ di chuyển đúng một bước
            if (steps == 8 && (dx == dx_knight)) break;
        }
    }
}

// Tính tổng giá trị của các ô không bị khống chế
int compute_score(vector<pair<int, int>> positions) {
    bool controlled[N][N] = {false};
    for (int i = 0; i < 4; i++) {
        int x = positions[i].first, y = positions[i].second;
        if (i == 0) mark_control(x, y, dx_queen, dy_queen, 8, controlled);  // Hậu
        if (i == 1) mark_control(x, y, dx_rook, dy_rook, 4, controlled);    // Xe
        if (i == 2) mark_control(x, y, dx_bishop, dy_bishop, 4, controlled); // Voi
        if (i == 3) mark_control(x, y, dx_knight, dy_knight, 8, controlled); // Ngựa
    }

    int score = 0;
    for (const auto &cell : cells) {
        if (!controlled[cell.x][cell.y]) {
            score += cell.value;
        }
    }
    return score;
}

int main() {
    ifstream fin("BONUS.INP");
    ofstream fout("BONUS.OUT");

    // Đọc dữ liệu
    int k;
    fin >> k;
    cells.resize(k);

    for (int i = 0; i < k; i++) {
        int u, v, c;
        fin >> u >> v >> c;
        cells[i] = {u - 1, v - 1, c}; // Đổi về chỉ số 0-based
    }

    // Duyệt tổ hợp vị trí đặt 4 quân
    int max_score = 0;
    for (int q1 = 0; q1 < N * N; q1++) {
        for (int q2 = q1 + 1; q2 < N * N; q2++) {
            for (int q3 = q2 + 1; q3 < N * N; q3++) {
                for (int q4 = q3 + 1; q4 < N * N; q4++) {
                    vector<pair<int, int>> positions = {
                        {q1 / N, q1 % N}, {q2 / N, q2 % N},
                        {q3 / N, q3 % N}, {q4 / N, q4 % N}};
                    max_score = max(max_score, compute_score(positions));
                }
            }
        }
    }

    // Ghi kết quả
    fout << max_score << endl;

    fin.close();
    fout.close();

    return 0;
}
