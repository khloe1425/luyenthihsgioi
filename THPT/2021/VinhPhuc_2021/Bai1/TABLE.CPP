#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// Hàm tính tổng tích lũy
void computePrefixSums(const vector<vector<int>>& table, vector<long long>& rowSums, vector<long long>& colSums) {
    int m = table.size();
    int n = table[0].size();

    // Tính tổng theo từng hàng
    for (int i = 0; i < m; ++i) {
        rowSums[i + 1] = rowSums[i];
        for (int j = 0; j < n; ++j) {
            rowSums[i + 1] += table[i][j];
        }
    }

    // Tính tổng theo từng cột
    for (int j = 0; j < n; ++j) {
        colSums[j + 1] = colSums[j];
        for (int i = 0; i < m; ++i) {
            colSums[j + 1] += table[i][j];
        }
    }
}

int main() {
    ifstream input("TABLE.INP");
    ofstream output("TABLE.OUT");

    int Q;
    input >> Q;

    for (int q = 0; q < Q; ++q) {
        int m, n;
        input >> m >> n;

        vector<vector<int>> table(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                input >> table[i][j];
            }
        }

        vector<long long> rowSums(m + 1, 0);
        vector<long long> colSums(n + 1, 0);

        // Tính tổng tích lũy
        computePrefixSums(table, rowSums, colSums);

        long long totalSum = rowSums[m]; // Tổng toàn bảng
        long long minDiff = totalSum;   // Chênh lệch nhỏ nhất
        string optimalCut = "V"; // Mặc định ưu tiên cắt dọc
        int optimalPos = 1;

        // Thử cắt dọc
        for (int x = 1; x < n; ++x) {
            long long leftSum = colSums[x];
            long long rightSum = totalSum - leftSum;
            long long diff = abs(leftSum - rightSum);

            if (diff < minDiff || (diff == minDiff && optimalCut == "H")) {
                minDiff = diff;
                optimalCut = "V";
                optimalPos = x;
            }
        }

        // Thử cắt ngang
        for (int x = 1; x < m; ++x) {
            long long topSum = rowSums[x];
            long long bottomSum = totalSum - topSum;
            long long diff = abs(topSum - bottomSum);

            if (diff < minDiff) {
                minDiff = diff;
                optimalCut = "H";
                optimalPos = x;
            }
        }

        // Ghi kết quả cho bảng hiện tại
        output << optimalCut << " " << optimalPos << endl;
    }

    input.close();
    output.close();

    return 0;
}
