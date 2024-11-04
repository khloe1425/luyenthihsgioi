#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Hàm tính tổng các chữ số của một số nguyên
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> sumCount; // Lưu số lần xuất hiện của mỗi tổng chữ số
    long long beautifulPairs = 0; // Số lượng cặp số đẹp

    // Đọc dãy số
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int sum = digitSum(a[i]); // Tính tổng chữ số
        beautifulPairs += sumCount[sum]; // Thêm số lượng cặp số đẹp có thể được tạo ra
        sumCount[sum]++; // Tăng số lần xuất hiện của tổng chữ số
    }

    cout << beautifulPairs << endl; // Xuất kết quả
    return 0;
}
