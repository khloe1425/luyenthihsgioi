#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("SOLPIN.INP");
    ofstream outputFile("SOLPIN.OUT");

    // Đọc kích thước bảng và mức hấp thụ ban đầu
    int m, n;
    inputFile >> m >> n;

    vector<vector<int>> grid(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            inputFile >> grid[i][j];
        }
    }

    // Đọc số lượng lệnh hoặc yêu cầu
    int q;
    inputFile >> q;

    vector<int> result; // Lưu kết quả các yêu cầu tính toán
    for (int k = 0; k < q; ++k) {
        int p;
        inputFile >> p;

        if (p == 0) {
            // Lệnh điều khiển
            int x, y;
            inputFile >> x >> y;
            if (x > 0) {
                // Lệnh R: Cập nhật mức hấp thụ theo hàng
                for (int j = 1; j <= n; ++j) {
                    grid[x][j] = y;
                }
            } else if (y > 0) {
                // Lệnh D: Cập nhật mức hấp thụ theo cột
                for (int i = 1; i <= m; ++i) {
                    grid[i][y] = x;
                }
            }
        } else if (p == 1) {
            // Yêu cầu tính toán
            int u, v, s, t;
            inputFile >> u >> v >> s >> t;

            long long sum = 0;
            for (int i = u; i <= s; ++i) {
                for (int j = v; j <= t; ++j) {
                    sum += grid[i][j];
                }
            }
            result.push_back(sum);
        }
    }

    // Ghi kết quả ra file
    for (int res : result) {
        outputFile << res << endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
