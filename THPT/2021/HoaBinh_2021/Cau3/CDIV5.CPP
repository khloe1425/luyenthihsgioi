#include <bits/stdc++.h>
using namespace std;

#define int long long

int findMaxDivisibleBy5(vector<int> &arr) {
    int n = arr.size();
    vector<int> mods(5, 0);

    // Đếm số phần tử có phần dư khi chia 5
    for (int x : arr) {
        mods[x % 5]++;
    }

    // Kết quả ban đầu là các phần tử đã chia hết cho 5
    int result = mods[0];

    // Cặp các phần tử có tổng chia hết cho 5
    int pair1 = min(mods[1], mods[4]);
    int pair2 = min(mods[2], mods[3]);

    result += pair1 + pair2;

    // Tính các phần tử lẻ còn lại từ cặp 1-4 và 2-3
    mods[1] -= pair1;
    mods[4] -= pair1;
    mods[2] -= pair2;
    mods[3] -= pair2;

    // Tính số phần tử lẻ còn lại, mỗi 2 phần tử tạo một phần tử mới
    result += mods[1] / 2;
    result += mods[4] / 2;
    result += mods[2] / 2;
    result += mods[3] / 2;

    return result;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Đọc input từ file và ghi output ra file
    freopen("CDIV5.INP", "r", stdin);
    freopen("CDIV5.OUT", "w", stdout);

    int q; // Số truy vấn
    cin >> q;

    while (q--) {
        int n; // Số phần tử của mảng
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << findMaxDivisibleBy5(arr) << '\n';
    }

    return 0;
}
