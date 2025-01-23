#include <bits/stdc++.h>
using namespace std;

#define int long long

// Hàm đếm tần suất ký tự trong chuỗi
vector<int> countFrequency(const string &s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    return freq;
}

// Hàm kiểm tra có thể làm cho các chuỗi bằng nhau hay không
bool canMakeEqual(vector<string> &strings, int n) {
    vector<int> totalFrequency(26, 0);

    // Cộng tổng tần suất của tất cả các ký tự trong n chuỗi
    for (const string &s : strings) {
        vector<int> freq = countFrequency(s);
        for (int i = 0; i < 26; i++) {
            totalFrequency[i] += freq[i];
        }
    }

    // Kiểm tra xem mỗi ký tự có thể chia đều cho n chuỗi không
    for (int i = 0; i < 26; i++) {
        if (totalFrequency[i] % n != 0) {
            return false;
        }
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Đọc input từ file
    freopen("CSTRING.INP", "r", stdin);
    freopen("CSTRING.OUT", "w", stdout);

    int q; // Số lượng truy vấn
    cin >> q;

    while (q--) {
        int n; // Số lượng chuỗi
        cin >> n;

        vector<string> strings(n);
        for (int i = 0; i < n; i++) {
            cin >> strings[i];
        }

        if (canMakeEqual(strings, n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
