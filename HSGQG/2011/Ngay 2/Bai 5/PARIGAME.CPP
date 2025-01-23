#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    // Đọc dữ liệu từ file
    ifstream input("PARIGAME.INP");
    ofstream output("PARIGAME.OUT");

    int k; // Số lượng bảng
    input >> k;

    while (k--) {
        int n;
        input >> n;

        vector<vector<int>> board(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                input >> board[i][j];
            }
        }

        int evenRows = 0, evenCols = 0;

        // Kiểm tra các hàng
        for (int i = 0; i < n; ++i) {
            int rowSum = 0;
            for (int j = 0; j < n; ++j) {
                rowSum += board[i][j];
            }
            if (rowSum % 2 == 0) {
                evenRows++;
            }
        }

        // Kiểm tra các cột
        for (int j = 0; j < n; ++j) {
            int colSum = 0;
            for (int i = 0; i < n; ++i) {
                colSum += board[i][j];
            }
            if (colSum % 2 == 0) {
                evenCols++;
            }
        }

        // XOR để xác định người thắng
        if ((evenRows ^ evenCols) != 0) {
            output << "YES" << endl;
        } else {
            output << "NO" << endl;
        }
    }

    input.close();
    output.close();
    return 0;
}
