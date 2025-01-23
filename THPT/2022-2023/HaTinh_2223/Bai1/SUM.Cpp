#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    // Mở file input và output
    freopen("SUM.INP", "r", stdin);
    freopen("SUM.OUT", "w", stdout);

    int n;
    cin >> n; // Đọc số phần tử của mảng

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Đọc các phần tử của mảng
    }

    // Biến đếm số đoạn con và tổng tiền tố
    long long count = 0;
    long long prefix_sum = 0;
    unordered_map<long long, int> prefix_count;

    // Ban đầu thêm tổng tiền tố bằng 0 vào map
    prefix_count[0] = 1;

    for (int i = 0; i < n; ++i) {
        prefix_sum += a[i];

        // Nếu tổng tiền tố đã xuất hiện trước đó
        if (prefix_count.find(prefix_sum) != prefix_count.end()) {
            count += prefix_count[prefix_sum];
        }

        // Tăng số lần xuất hiện của tổng tiền tố hiện tại
        prefix_count[prefix_sum]++;
    }

    // Ghi kết quả ra file
    cout << count << endl;

    return 0;
}
