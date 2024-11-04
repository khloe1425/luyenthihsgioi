#include <iostream>
using namespace std;

// Hàm tính GCD sử dụng thuật toán Euclid
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    cin >> n; // Số lượng cặp (a, b)

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b; // Nhập cặp a, b

        int k = 0; // Số vòng xoay
        // Kiểm tra GCD ban đầu
        while (gcd(a, b + k) == 1) { // Sử dụng hàm tự định nghĩa
            k++; // Tăng k
        }
        
        cout << k << endl; // Xuất số vòng xoay cần thiết
    }

    return 0;
}
