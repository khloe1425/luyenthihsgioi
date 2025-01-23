#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Định nghĩa các hướng di chuyển: phải và xuống
const int dx[] = {0, 1};
const int dy[] = {1, 0};

// Kiểm tra vị trí hợp lệ trong bảng
bool isValid(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

// Hàm đếm số đường đi chứa từ khóa P
int countPaths(const vector<string> &board, const string &P, int m, int n, int D) {
    int count = 0;

    // Duyệt qua từng ô trên bảng
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // Duyệt qua hai hướng (phải, xuống)
            for (int dir = 0; dir < 2; ++dir) {
                string path = "";
                int x = i, y = j;

                // Tạo chuỗi kết quả trên đường đi
                while (isValid(x, y, m, n)) {
                    path += board[x][y];

                    // Kiểm tra từ khóa P trong đường đi
                    if (path.find(P) != string::npos) {
                        count++;
                        break; // Dừng tìm kiếm khi tìm thấy từ khóa P
                    }

                    // Di chuyển theo hướng chỉ định
                    x += dx[dir];
                    y += dy[dir];
                }
            }
        }
    }

    return count % D; // Trả về kết quả chia dư cho D
}

int main() {
    ifstream inputFile("TROCHOI.INP");
    ofstream outputFile("TROCHOI.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int m, n, D;
    string P;

    // Đọc dữ liệu từ file
    inputFile >> m >> n >> D;
    inputFile >> P;

    vector<string> board(m);
    for (int i = 0; i < m; ++i) {
        inputFile >> board[i];
    }

    // Tính số đường đi hợp lệ
    int result = countPaths(board, P, m, n, D);

    // Ghi kết quả ra file
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
