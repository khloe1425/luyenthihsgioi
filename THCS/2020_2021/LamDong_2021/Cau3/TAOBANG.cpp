#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Hàm tạo bảng n x n theo quy luật
vector<vector<int>> generateTable(int n) {
    vector<vector<int>> table(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        int value = (i % 2 == 0) ? (i + 1) : (2 * (i / 2 + 1)); // Dòng lẻ: số lẻ, dòng chẵn: số chẵn
        for (int j = 0; j < n; j++) {
            table[i][j] = value * (j + 1);
        }
    }
    return table;
}

int main() {
    ifstream inputFile("TAOBANG.INP");
    ofstream outputFile("TAOBANG.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    if (n < 1 || n > 600) {
        cerr << "Giá trị n không hợp lệ." << endl;
        return 1;
    }

    vector<vector<int>> table = generateTable(n);

    // Xuất kết quả ra file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outputFile << table[i][j];
            if (j < n - 1) outputFile << " ";
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
