#include <iostream>
#include <vector>
using namespace std;

// Modulo
const long long MOD = 123456789;

// Hàm tính số phân hoạch sử dụng quy hoạch động
long long partitionCount(int N) {
    vector<long long> dp(N + 1, 0);
    dp[0] = 1; // Có một cách phân hoạch số 0 (dãy rỗng)

    // Quy hoạch động: Cập nhật số phân hoạch cho từng giá trị
    for (int i = 1; i <= N; ++i) {         // Xét từng số hạng (số nguyên dương)
        for (int j = i; j <= N; ++j) {     // Cập nhật với tổng từ i đến N
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    return dp[N]; // Kết quả là số phân hoạch của N
}

int main() {
    // Mở file input và output
    freopen("SoNguyen.INP", "r", stdin);
    freopen("SoNguyen.OUT", "w", stdout);

    int N;
    cin >> N;

    // Tính số phân hoạch và ghi kết quả ra file
    cout << partitionCount(N) << endl;

    return 0;
}
