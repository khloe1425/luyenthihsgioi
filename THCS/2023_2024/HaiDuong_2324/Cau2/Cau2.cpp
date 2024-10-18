#include <iostream>
using namespace std;

int main() {
    // Nhập số nguyên dương n
    long long n;
    cin >> n;

    // Khởi tạo biến tổng
    long long total_sum = 0;

    // Tính tổng các chữ số
    while (n > 0) {
        total_sum += n % 10;  // Lấy chữ số cuối và cộng vào tổng
        n /= 10;               // Cập nhật n bằng cách bỏ chữ số cuối
    }

    // In ra kết quả
    cout << total_sum << endl;

    return 0;
}
