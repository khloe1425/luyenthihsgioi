#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <fstream>
using namespace std;

void solve(int N, vector<int> &A, ostream &out) {
    // Tạo dãy B khả dĩ từ A (không trùng lặp và sắp xếp tăng dần)
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    sortedA.erase(unique(sortedA.begin(), sortedA.end()), sortedA.end());

    int M = sortedA.size();
    vector<vector<long long>> dp(N, vector<long long>(M, LLONG_MAX)); // Bảng DP
    vector<vector<int>> trace(N, vector<int>(M, -1));   // Lưu vết để truy ngược

    // Khởi tạo DP cho vị trí đầu tiên
    for (int j = 0; j < M; j++) {
        dp[0][j] = abs(A[0] - sortedA[j]);
    }

    // Điền bảng DP với tối ưu hóa
    for (int i = 1; i < N; i++) {
        vector<long long> minPrev(M, LLONG_MAX);
        minPrev[0] = dp[i - 1][0];
        for (int j = 1; j < M; j++) {
            minPrev[j] = min(minPrev[j - 1], dp[i - 1][j]);
        }
        for (int j = 0; j < M; j++) {
            dp[i][j] = minPrev[j] + abs(A[i] - sortedA[j]);
            trace[i][j] = (dp[i][j] == minPrev[j] + abs(A[i] - sortedA[j])) ? j : trace[i][j];
        }
    }

    // Tìm giá trị độ chênh lệch nhỏ nhất
    long long minDiff = LLONG_MAX;
    int lastIndex = -1;
    for (int j = 0; j < M; j++) {
        if (dp[N - 1][j] < minDiff) {
            minDiff = dp[N - 1][j];
            lastIndex = j;
        }
    }

    // Truy vết để tìm dãy B
    vector<int> B(N);
    for (int i = N - 1; i >= 0; i--) {
        B[i] = sortedA[lastIndex];
        lastIndex = trace[i][lastIndex];
    }

    // In kết quả
    out << minDiff << endl;
    for (int i = 0; i < N; i++) {
        out << B[i] << " ";
    }
    out << endl;
}

int main() {
    // Đọc dữ liệu từ file
    ifstream fin("SEQUENCE.INP");
    ofstream fout("SEQUENCE.OUT");

    int N;
    fin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        fin >> A[i];
    }

    solve(N, A, fout);

    fin.close();
    fout.close();

    return 0;
}
