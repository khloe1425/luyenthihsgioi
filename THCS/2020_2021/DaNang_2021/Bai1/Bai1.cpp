#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int k;
    cout << "Nhap k: ";
    cin >> k;

    // Độ dài của số nguyên tố cân bằng
    int length = 2 * k + 1;

    // Biến đếm số nguyên tố cân bằng
    int count = 0;

    // Tạo số nguyên tố cân bằng
    for (int d = 1; d <= 9; ++d) {  // Chữ số giống nhau
        for (int m = 0; m <= 9; ++m) { // Chữ số khác ở giữa
            if (m == d) continue;

            // Tạo số nguyên tố cân bằng
            long long balancedNumber = 0;
            for (int i = 0; i < k; ++i) {
                balancedNumber = balancedNumber * 10 + d;
            }
            balancedNumber = balancedNumber * 10 + m; // Chữ số giữa
            for (int i = 0; i < k; ++i) {
                balancedNumber = balancedNumber * 10 + d;
            }

            // Kiểm tra số nguyên tố
            if (isPrime(balancedNumber)) {
                count++;
            }
        }
    }

    // In kết quả
    cout << count << endl;

    return 0;
}
