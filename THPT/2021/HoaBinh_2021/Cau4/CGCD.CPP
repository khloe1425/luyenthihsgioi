#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

// Hàm nhân hai số và chia lấy dư cho MOD
int modMul(int a, int b, int mod) {
    return (a % mod) * (b % mod) % mod;
}

// Hàm tính USCLN giữa hai số rất lớn
int gcdLarge(int a, int b) {
    return b == 0 ? a : gcdLarge(b, a % b);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Đọc file input và ghi file output
    freopen("CGCD.INP", "r", stdin);
    freopen("CGCD.OUT", "w", stdout);

    int N, M; // Số lượng phần tử của 2 dãy
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cin >> M;
    vector<int> b(M);
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }

    // Tính tích của dãy a và b dưới modulo MOD
    int productA = 1, productB = 1;

    for (int i = 0; i < N; i++) {
        productA = modMul(productA, a[i], MOD);
    }

    for (int i = 0; i < M; i++) {
        productB = modMul(productB, b[i], MOD);
    }

    // Tìm USCLN của 2 tích
    int result = gcdLarge(productA, productB);

    // In kết quả
    cout << result << '\n';

    return 0;
}
