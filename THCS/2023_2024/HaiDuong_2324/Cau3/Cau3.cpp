#include <iostream>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false; // Số nhỏ hơn 2 không phải số nguyên tố
    if (num == 2) return true; // 2 là số nguyên tố
    if (num % 2 == 0) return false; // Các số chẵn lớn hơn 2 không phải số nguyên tố

    for (int i = 3; i * i <= num; i += 2) { // Kiểm tra các số lẻ từ 3 đến sqrt(num)
        if (num % i == 0) {
            return false; // Nếu num chia hết cho i, num không phải số nguyên tố
        }
    }
    return true; // num là số nguyên tố
}

int main() {
    // Nhập số nguyên dương n
    int n;
    cin >> n;

    // Tìm số nguyên tố nhỏ nhất lớn hơn hoặc bằng n
    while (!isPrime(n)) {
        n++; // Tăng n lên cho đến khi tìm được số nguyên tố
    }

    // In ra kết quả
    cout << n << endl;

    return 0;
}
