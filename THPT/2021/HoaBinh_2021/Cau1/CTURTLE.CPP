#include <bits/stdc++.h>
using namespace std;

#define int long long

// Hàm tính tổng khoảng cách tối thiểu giữa 3 con rùa
int calculateMinDistance(int a, int b, int c) {
    vector<int> positions = {a, b, c};
    sort(positions.begin(), positions.end()); // Sắp xếp vị trí từ nhỏ đến lớn
    int mid = positions[1]; // Vị trí giữa sau khi sắp xếp
    // Tổng khoảng cách tối thiểu giữa các cặp
    return (abs(mid - positions[0]) + abs(mid - positions[2]));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Mở file input và output
    freopen("CTURTLE.INP", "r", stdin);
    freopen("CTURTLE.OUT", "w", stdout);

    int q; // Số lượng truy vấn
    cin >> q;

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << calculateMinDistance(a, b, c) << '\n';
    }

    return 0;
}
