#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("TongUoc.Inp");
    ofstream fout("TongUoc.Out");

    ll a, b;
    fin >> a >> b;

    set<ll> validX; // Dùng set để tránh trùng lặp các giá trị x

    // Tìm ước của a và kiểm tra điều kiện 3x là ước của b
    for (ll i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            // i là ước của a
            if (b % (3 * i) == 0) validX.insert(i);
            // a / i là ước của a
            if (b % (3 * (a / i)) == 0) validX.insert(a / i);
        }
    }

    // Tính tổng các giá trị x thỏa mãn
    ll sum = 0;
    for (ll x : validX) {
        sum += x;
    }

    fout << sum << "\n";

    fin.close();
    fout.close();
    return 0;
}
