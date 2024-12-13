#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

void spiralOrder(const vector<vector<int>>& matrix, vector<vector<int>>& result, int M, int N) {
    int top = 0, bottom = M - 1, left = 0, right = N - 1;
    int currentNum = 0;

    while (top <= bottom && left <= right) {
        // Từ trái sang phải
        for (int i = left; i <= right; ++i) {
            result[top][i] = currentNum++;
        }
        top++;

        // Từ trên xuống dưới
        for (int i = top; i <= bottom; ++i) {
            result[i][right] = currentNum++;
        }
        right--;

        if (top <= bottom) {
            // Từ phải sang trái
            for (int i = right; i >= left; --i) {
                result[bottom][i] = currentNum++;
            }
            bottom--;
        }

        if (left <= right) {
            // Từ dưới lên trên
            for (int i = bottom; i >= top; --i) {
                result[i][left] = currentNum++;
            }
            left++;
        }
    }
}

int main() {
    ifstream input("Cau2.INP");
    ofstream output("Cau2.OUT");

    int M, N;
    input >> M >> N;

    vector<vector<int>> matrix(M, vector<int>(N));
    vector<vector<int>> spiralResult(M, vector<int>(N, 0));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            input >> matrix[i][j];
        }
    }

    spiralOrder(matrix, spiralResult, M, N);

    // Ghi kết quả vào file dưới dạng ma trận
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            output << spiralResult[i][j] << " ";
        }
        output << endl;
    }

    input.close();
    output.close();

    return 0;
}
