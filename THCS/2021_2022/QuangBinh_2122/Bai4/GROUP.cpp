#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ifstream input("GROUP.INP");
    ofstream output("GROUP.OUT");

    int N, K;
    input >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        input >> a[i];
    }

    // Khởi tạo mảng dp với K + 1 phần tử
    vector<long long> dp(K + 1, 0);
    dp[0] = 1; // Có 1 cách để tạo tổng bằng 0 (không chọn ai)

    // Duyệt qua từng bạn và cập nhật trạng thái dp
    for (int i = 0; i < N; ++i) {
        for (int j = K; j >= a[i]; --j) {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }

    // Kết quả là dp[K]
    output << dp[K] << endl;

    input.close();
    output.close();
    return 0;
}
