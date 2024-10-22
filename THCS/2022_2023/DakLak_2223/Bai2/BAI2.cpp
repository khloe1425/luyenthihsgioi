#include <iostream>
#include <vector>

using namespace std;

// Hàm kiểm tra số nguyên n có phải là số nguyên tố hay không
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm kiểm tra số nguyên n có phải là số nguyên tố "đẹp" hay không
bool is_beautiful_prime(int n) {
    if (!is_prime(n)) return false;
    // Kiểm tra xem n có chứa chữ số 3, 5, hoặc 7 không
    while (n > 0) {
        int digit = n % 10;
        if (digit == 3 || digit == 5 || digit == 7) return false;
        n /= 10;
    }
    return true;
}

// Hàm đếm số lượng số nguyên tố "đẹp" từ 1 đến N
int count_beautiful_primes(int N) {
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (is_beautiful_prime(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    cout << "Nhập số nguyên dương N: ";
    cin >> N;

    int result = count_beautiful_primes(N);
    cout << result << endl;

    return 0;
}
