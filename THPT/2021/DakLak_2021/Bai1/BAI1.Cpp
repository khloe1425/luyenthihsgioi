#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile("BAI1.INP");  // Mở file đầu vào
    ofstream outputFile("BAI1.OUT"); // Mở file đầu ra

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    vector<int> rowSum(N, 0), colSum(N, 0);

    // Đọc ma trận và tính tổng các dòng và cột
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> matrix[i][j];
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }

    // Kiểm tra các ô (i, j)
    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (rowSum[i] == colSum[j]) {
                count++;
            }
        }
    }

    outputFile << count << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
