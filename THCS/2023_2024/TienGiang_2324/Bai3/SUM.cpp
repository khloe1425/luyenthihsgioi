#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    ifstream input("SUM.INP");
    ofstream output("SUM.OUT");
    
    int m, n;
    input >> m >> n; // Đọc kích thước ma trận
    vector<vector<int>> a(m, vector<int>(n)); // Khai báo ma trận a

    // Đọc ma trận a
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            input >> a[i][j];
        }
    }

    // Tính tổng dòng và tổng cột
    vector<int> row_sum(m, 0);
    vector<int> col_sum(n, 0);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            row_sum[i] += a[i][j]; // Tính tổng dòng i
            col_sum[j] += a[i][j]; // Tính tổng cột j
        }
    }

    int min_value = numeric_limits<int>::max(); // Khởi tạo giá trị nhỏ nhất

    // Tính ma trận b và tìm giá trị nhỏ nhất
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int b_ij = (row_sum[i] + col_sum[j]) - a[i][j];
            min_value = min(min_value, b_ij); // Cập nhật giá trị nhỏ nhất
        }
    }

    // Ghi kết quả vào tệp
    output << min_value << endl;

    input.close();
    output.close();

    return 0;
}
