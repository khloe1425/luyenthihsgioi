#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Hàm kiểm tra tính hợp lệ
bool isValid(const vector<int>& a, int n, int k, int maxSum) {
    int currentSum = 0, segments = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] > maxSum) return false; // Nếu phần tử lớn hơn maxSum thì không thể chia
        if (currentSum + a[i] > maxSum) {
            ++segments;
            currentSum = a[i];
            if (segments > k) return false;
        } else {
            currentSum += a[i];
        }
    }
    return true;
}

int main() {
    // Đọc dữ liệu từ file
    freopen("SEGPAR.INP", "r", stdin);
    freopen("SEGPAR.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Tìm kiếm nhị phân để tìm giá trị nhỏ nhất của M
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isValid(a, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Ghi kết quả ra file
    cout << result << endl;

    return 0;
}
