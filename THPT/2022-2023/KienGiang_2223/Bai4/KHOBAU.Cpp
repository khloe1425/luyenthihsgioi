#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Định nghĩa các hướng di chuyển
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Kiểm tra xem tọa độ (x, y) có nằm trong bảng không
bool isValid(int x, int y, int M, int N) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

// Kiểm tra xem bảng kho báu có khớp bảng mã hóa không
bool validateTreasureMap(const vector<vector<int>>& treasureMap, const vector<vector<int>>& encodedMap, int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int sum = 0;

            // Tính tổng kho báu từ các ô xung quanh và chính ô (i, j)
            for (int k = 0; k < 8; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (isValid(ni, nj, M, N)) {
                    sum += treasureMap[ni][nj];
                }
            }
            sum += treasureMap[i][j];

            // Nếu không khớp mã hóa, trả về false
            if (sum != encodedMap[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Tìm bảng kho báu từ bảng mã hóa
bool findTreasureMap(const vector<vector<int>>& encodedMap, vector<vector<int>>& treasureMap, int M, int N) {
    // Thử tất cả các khả năng của bảng kho báu (0 hoặc 1 cho mỗi ô)
    for (int i = 0; i < (1 << (M * N)); ++i) {
        // Biến i đại diện cho trạng thái của bảng kho báu
        int bitIndex = 0;
        for (int r = 0; r < M; ++r) {
            for (int c = 0; c < N; ++c) {
                treasureMap[r][c] = (i & (1 << bitIndex)) ? 1 : 0;
                bitIndex++;
            }
        }

        // Kiểm tra xem bảng kho báu hiện tại có khớp bảng mã hóa không
        if (validateTreasureMap(treasureMap, encodedMap, M, N)) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream inputFile("KHOBAU.INP");
    ofstream outputFile("KHOBAU.OUT");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return 1;
    }

    int M, N;
    inputFile >> M >> N;

    vector<vector<int>> encodedMap(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            inputFile >> encodedMap[i][j];
        }
    }

    vector<vector<int>> treasureMap(M, vector<int>(N, 0));

    if (findTreasureMap(encodedMap, treasureMap, M, N)) {
        outputFile << "YES" << endl;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                outputFile << treasureMap[i][j] << " ";
            }
            outputFile << endl;
        }
    } else {
        outputFile << "NO" << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
