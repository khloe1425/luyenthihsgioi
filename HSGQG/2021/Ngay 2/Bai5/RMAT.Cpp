#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm rút gọn một hàng
void reduceRow(vector<vector<int>>& matrix, int row) {
    for (int j = 0; j < matrix[row].size(); j++) {
        matrix[row][j] += matrix[row + 1][j];
    }
    matrix.erase(matrix.begin() + row + 1);
}

// Hàm rút gọn một cột
void reduceColumn(vector<vector<int>>& matrix, int col) {
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i][col] += matrix[i][col + 1];
        matrix[i].erase(matrix[i].begin() + col + 1);
    }
}

// Tính tổng số phần tử của ma trận
int calculateTotalElements(const vector<vector<int>>& matrix) {
    int total = 0;
    for (const auto& row : matrix) {
        total += row.size();
    }
    return total;
}

int main() {
    ifstream fin("RMAT.INP");
    ofstream fout("RMAT.OUT");

    if (!fin || !fout) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    // Đọc ma trận từ input
    int m, n;
    fin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> matrix[i][j];
        }
    }

    // Thực hiện các thao tác rút gọn
    while (true) {
        int minElements = calculateTotalElements(matrix);
        int bestRow = -1, bestCol = -1;

        // Tìm thao tác rút gọn hàng tốt nhất
        for (int i = 0; i < matrix.size() - 1; i++) {
            vector<vector<int>> temp = matrix;
            reduceRow(temp, i);
            int newElements = calculateTotalElements(temp);
            if (newElements < minElements) {
                minElements = newElements;
                bestRow = i;
                bestCol = -1;
            }
        }

        // Tìm thao tác rút gọn cột tốt nhất
        for (int j = 0; j < matrix[0].size() - 1; j++) {
            vector<vector<int>> temp = matrix;
            reduceColumn(temp, j);
            int newElements = calculateTotalElements(temp);
            if (newElements < minElements) {
                minElements = newElements;
                bestRow = -1;
                bestCol = j;
            }
        }

        // Thực hiện thao tác rút gọn tốt nhất
        if (bestRow != -1) {
            reduceRow(matrix, bestRow);
        } else if (bestCol != -1) {
            reduceColumn(matrix, bestCol);
        } else {
            break; // Không thể rút gọn thêm
        }
    }

    // Ghi kết quả ra file
    fout << calculateTotalElements(matrix) << endl;

    fin.close();
    fout.close();

    return 0;
}
