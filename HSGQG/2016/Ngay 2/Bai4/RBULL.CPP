#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// Hàm kiểm tra số lượng cọc bò trong phạm vi hình thoi
int countCows(const vector<string>& grid, int x0, int y0, int r, int m, int n) {
    int count = 0;
    for (int x = max(0, x0 - r); x <= min(m - 1, x0 + r); ++x) {
        int y_start = max(0, y0 - (r - abs(x - x0)));
        int y_end = min(n - 1, y0 + (r - abs(x - x0)));
        for (int y = y_start; y <= y_end; ++y) {
            if (grid[x][y] == '*') {
                count++;
            }
        }
    }
    return count;
}

// Hàm kiểm tra tính hợp lệ của phạm vi hình thoi
bool isValid(const vector<string>& grid, int x0, int y0, int r, int m, int n) {
    for (int x = max(0, x0 - r); x <= min(m - 1, x0 + r); ++x) {
        int y_start = max(0, y0 - (r - abs(x - x0)));
        int y_end = min(n - 1, y0 + (r - abs(x - x0)));
        for (int y = y_start; y <= y_end; ++y) {
            if (grid[x][y] == '*') {
                // Kiểm tra các ô liền kề
                if (x > 0 && grid[x - 1][y] == '*') return false;
                if (x < m - 1 && grid[x + 1][y] == '*') return false;
                if (y > 0 && grid[x][y - 1] == '*') return false;
                if (y < n - 1 && grid[x][y + 1] == '*') return false;
            }
        }
    }
    return true;
}

int main() {
    ifstream input("RBULL.INP");
    ofstream output("RBULL.OUT");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int m, n;
    input >> m >> n;

    vector<string> grid(m);
    for (int i = 0; i < m; ++i) {
        input >> grid[i];
    }

    int maxCows = 0, bestX = 1, bestY = 1, bestR = 0;

    // Duyệt qua tất cả các ô làm tâm
    for (int x0 = 0; x0 < m; ++x0) {
        for (int y0 = 0; y0 < n; ++y0) {
            for (int r = 0; r <= max(m, n); ++r) {
                if (isValid(grid, x0, y0, r, m, n)) {
                    int cows = countCows(grid, x0, y0, r, m, n);
                    if (cows > maxCows) {
                        maxCows = cows;
                        bestX = x0 + 1; // Đổi sang toạ độ bắt đầu từ 1
                        bestY = y0 + 1; // Đổi sang toạ độ bắt đầu từ 1
                        bestR = r;
                    }
                }
            }
        }
    }

    output << maxCows << " " << bestX << " " << bestY << " " << bestR << endl;

    input.close();
    output.close();

    return 0;
}
