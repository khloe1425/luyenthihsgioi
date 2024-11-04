#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inp("VUONCAY.INP");
    ofstream out("VUONCAY.OUT");

    int M, N;
    inp >> M >> N;

    vector<vector<int>> garden(M, vector<int>(N));

    // Đọc dữ liệu từ file
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            inp >> garden[i][j];
        }
    }

    int total_length = 0;

    // Chu vi ngoài của mảnh vườn
    total_length += 2 * (M + N);

    // Kiểm tra các cạnh giữa các ô đất
    // Kiểm tra các cạnh ngang (các ô trong cùng hàng)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (garden[i][j] != garden[i][j + 1]) {
                total_length += 1; // Thêm dây ngang
            }
        }
    }

    // Kiểm tra các cạnh dọc (các ô trong cùng cột)
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < N; j++) {
            if (garden[i][j] != garden[i + 1][j]) {
                total_length += 1; // Thêm dây dọc
            }
        }
    }

    // Ghi kết quả ra file
    out << total_length << endl;

    return 0;
}
