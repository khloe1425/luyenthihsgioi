#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
    // Đọc dữ liệu từ file WHOOME.INP
    ifstream inputFile("WHOOME.INP");
    ofstream outputFile("WHOOME.OUT");

    int N, M;
    ll P, C;
    inputFile >> N >> M >> P >> C;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        inputFile >> A[i];
    }

    vector<int> S(M);
    for (int i = 0; i < M; ++i) {
        inputFile >> S[i];
    }

    // Sắp xếp chiều cao các cột gỗ
    sort(A.begin(), A.end());

    // DP[j]: Lợi nhuận lớn nhất khi chọn j mẫu nhà
    vector<ll> DP(M + 1, -INF);
    DP[0] = 0;

    // Tính DP
    for (int k = 0; k < M; ++k) { // Duyệt từng mẫu nhà
        int required = S[k];
        vector<ll> newDP(M + 1, -INF); // Dùng mảng tạm để lưu trạng thái mới

        // Duyệt qua tất cả các đoạn có thể chọn
        for (int i = 0; i + required <= N; ++i) {
            ll max_height = A[i + required - 1];
            ll min_height = A[i];
            ll cost = (max_height - min_height) * (max_height - min_height) * C;
            ll profit = P - cost;

            if (profit >= 0) {
                for (int j = 0; j <= k; ++j) {
                    newDP[j + 1] = max(newDP[j + 1], DP[j] + profit);
                }
            }
        }

        // Cập nhật DP
        DP = newDP;
    }

    // Kết quả là giá trị lớn nhất khi chọn M mẫu nhà
    ll result = DP[M];
    outputFile << result << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
