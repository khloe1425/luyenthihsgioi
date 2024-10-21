#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // Mở file để đọc dữ liệu
    ifstream infile("CAU4.INP");
    // Kiểm tra xem file có mở thành công hay không
    if (!infile.is_open()) {
        cerr << "Không thể mở file CAU4.INP" << endl;
        return 1;
    }

    int n;
    infile >> n; // Đọc số lượng cặp

    int ans = 0;
    map<int, int> mp;
    map<pair<int, int>, int> mp2;

    for (int i = 1; i <= n; i++) {
        int a, b;
        infile >> a >> b; // Đọc các cặp số a và b

        int gcd_value = __gcd(a, b);
        int ff = a / gcd_value;
        int ss = b / gcd_value;

        ans += mp[a] - mp2[make_pair(ff, ss)];
        mp[a]++;
        mp2[{ff, ss}]++;
    }

    // Đóng file input
    infile.close();

    // In kết quả ra file output
    ofstream outfile("CAU4.OUT");
    if (!outfile.is_open()) {
        cerr << "Không thể mở file CAU4.OUT" << endl;
        return 1;
    }

    outfile << ans; // Ghi kết quả vào file
    outfile.close();

    return 0;
}
