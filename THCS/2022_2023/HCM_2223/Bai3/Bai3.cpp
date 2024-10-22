#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

// Hàm tính lũy thừa modulo
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Hàm tính nghịch đảo modulo sử dụng Fermat's Little Theorem
long long mod_inverse(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);
}

// Hàm tính tổ hợp C(n, k)
long long nCr(long long n, long long k, long long mod) {
    if (k > n) return 0;
    long long numerator = 1, denominator = 1;
    for (long long i = 0; i < k; ++i) {
        numerator = (numerator * (n - i)) % mod; // Tính n * (n-1) * ... * (n-k+1)
        denominator = (denominator * (i + 1)) % mod; // Tính k!
    }
    return (numerator * mod_inverse(denominator, mod)) % mod; // C(n, k) = numerator / denominator
}

int main() {
    int n, K;
    cin >> n >> K;
    vector<int> A(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    // Sắp xếp mảng A theo thứ tự giảm dần
    sort(A.rbegin(), A.rend());
    
    // Tính tổng K phần tử lớn nhất
    long long total_sum = 0;
    for (int i = 0; i < K; ++i) {
        total_sum = (total_sum + A[i]) % MOD;
    }
    
    // Tính số cách chọn K phần tử không liên tiếp từ n phần tử
    long long ways = nCr(n - K + 1, K, MOD); // Số cách chọn K phần tử không liên tiếp

    // Tổng số cách
    long long total_ways = (total_sum * ways) % MOD;
    
    cout << total_ways << endl;

    return 0;
}
