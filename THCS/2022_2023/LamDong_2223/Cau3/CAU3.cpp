#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

// Hàm để xử lý các thao tác trên dãy số
void processQueries(int N, int Q, vector<long long>& A, ifstream& inputFile, ofstream& outputFile) {
    for (int i = 0; i < Q; ++i) {
        int queryType;
        inputFile >> queryType; // Đọc loại thao tác

        if (queryType == 1) {
            // Thao tác loại 1: Tăng giá trị
            int p, m, x;
            inputFile >> p >> m >> x; // Đọc p, m và x
            for (int j = p - 1; j < m; ++j) { // Chuyển đổi sang chỉ số bắt đầu từ 0
                A[j] += x; // Tăng giá trị
            }
        } else if (queryType == 2) {
            // Thao tác loại 2: Tính tổng
            int u, v;
            inputFile >> u >> v; // Đọc u và v
            long long sum = accumulate(A.begin() + (u - 1), A.begin() + v, 0LL); // Tính tổng
            outputFile << sum << endl; // Ghi kết quả
        }
    }
}

int main() {
    ifstream inputFile("CAU3.INP");
    ofstream outputFile("CAU3.OUT");

    int N, Q;
    inputFile >> N >> Q; // Đọc N và Q
    vector<long long> A(N);

    // Đọc dãy số
    for (int i = 0; i < N; ++i) {
        inputFile >> A[i];
    }

    // Xử lý các thao tác
    processQueries(N, Q, A, inputFile, outputFile);

    inputFile.close();
    outputFile.close();
    return 0;
}
