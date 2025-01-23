#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Hàm kiểm tra hình vuông ma thuật
bool isMagicSquare(const vector<vector<int>>& matrix) {
    int size = 4; // Kích thước 4x4
    int magicSum = 0;

    // Tính tổng của hàng đầu tiên
    for (int j = 0; j < size; ++j) {
        magicSum += matrix[0][j];
    }

    // Kiểm tra tổng các hàng
    for (int i = 0; i < size; ++i) {
        int rowSum = 0;
        for (int j = 0; j < size; ++j) {
            rowSum += matrix[i][j];
        }
        if (rowSum != magicSum) {
            return false;
        }
    }

    // Kiểm tra tổng các cột
    for (int j = 0; j < size; ++j) {
        int colSum = 0;
        for (int i = 0; i < size; ++i) {
            colSum += matrix[i][j];
        }
        if (colSum != magicSum) {
            return false;
        }
    }

    // Kiểm tra tổng đường chéo chính
    int diag1Sum = 0;
    for (int i = 0; i < size; ++i) {
        diag1Sum += matrix[i][i];
    }
    if (diag1Sum != magicSum) {
        return false;
    }

    // Kiểm tra tổng đường chéo phụ
    int diag2Sum = 0;
    for (int i = 0; i < size; ++i) {
        diag2Sum += matrix[i][size - i - 1];
    }
    if (diag2Sum != magicSum) {
        return false;
    }

    return true;
}

int main() {
    ifstream inputFile("MATHUAT.INP");
    ofstream outputFile("MATHUAT.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    vector<vector<int>> matrix(4, vector<int>(4));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            inputFile >> matrix[i][j];
        }
    }

    if (isMagicSquare(matrix)) {
        outputFile << "magic" << endl;
    } else {
        outputFile << "not magic" << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
