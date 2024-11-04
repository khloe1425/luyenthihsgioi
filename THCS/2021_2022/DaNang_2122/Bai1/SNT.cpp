#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra một số có phải số nguyên tố hay không
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int a;
    cout << "Nhập số nguyên dương a: ";
    cin >> a;

    int b = 1;
    while (!isPrime(a + b)) {
        b++;
    }

    cout << "Số nguyên dương b nhỏ nhất là: " << b << endl;
    return 0;
}
