#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm đọc dữ liệu từ file PAINT.INP
void read_paint_inp(const string& file_path, int& m, int& n, vector<vector<int>>& grid) {
    ifstream file(file_path);
    if (file.is_open()) {
        // Đọc dòng đầu tiên là kích thước m, n
        file >> m >> n;

        // Đọc lưới chiều cao các cột
        grid.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                file >> grid[i][j];
            }
        }
        file.close();
    }
}

// Hàm ghi kết quả vào file PAINT.OUT
void write_paint_out(const string& file_path, int result) {
    ofstream file(file_path);
    if (file.is_open()) {
        file << result << endl;
        file.close();
    }
}

// Hàm tính diện tích cần sơn
int calculate_painted_area(int m, int n, const vector<vector<int>>& grid) {
    int total_area = 0;

    // Cộng diện tích mặt trên
    total_area += m * n;

    // Duyệt qua từng ô trong lưới
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Lấy chiều cao cột tại vị trí (i, j)
            int height = grid[i][j];

            // Mặt trước: So sánh với cột phía trước (i-1)
            if (i == 0) {  // Ở rìa trên, luôn sơn mặt trước
                total_area += height;
            } else {
                total_area += max(0, height - grid[i - 1][j]);
            }

            // Mặt sau: So sánh với cột phía sau (i+1)
            if (i == m - 1) {  // Ở rìa dưới, luôn sơn mặt sau
                total_area += height;
            } else {
                total_area += max(0, height - grid[i + 1][j]);
            }

            // Mặt trái: So sánh với cột bên trái (j-1)
            if (j == 0) {  // Ở rìa trái, luôn sơn mặt trái
                total_area += height;
            } else {
                total_area += max(0, height - grid[i][j - 1]);
            }

            // Mặt phải: So sánh với cột bên phải (j+1)
            if (j == n - 1) {  // Ở rìa phải, luôn sơn mặt phải
                total_area += height;
            } else {
                total_area += max(0, height - grid[i][j + 1]);
            }
        }
    }

    return total_area;
}

int main() {
    // Đường dẫn tới file
    string file_path_inp = "paint.inp";
    string file_path_out = "paint.out";

    int m, n;
    vector<vector<int>> grid;

    // Đọc dữ liệu từ file PAINT.INP
    read_paint_inp(file_path_inp, m, n, grid);

    // Tính diện tích cần sơn
    int total_area = calculate_painted_area(m, n, grid);

    // Ghi kết quả vào PAINT.OUT
    write_paint_out(file_path_out, total_area);

    return 0;
}
