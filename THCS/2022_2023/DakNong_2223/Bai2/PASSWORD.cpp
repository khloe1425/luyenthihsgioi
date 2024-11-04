#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm tính tổng các chữ số của một số
int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    // Đọc dữ liệu từ file PASSWORD.INP
    ifstream input("PASSWORD.INP");
    int l, r;
    input >> l >> r;
    input.close();

    vector<int> specialPrimes;

    // Tìm các số nguyên tố trong khoảng [l, r]
    for (int i = l; i <= r; i++) {
        if (isPrime(i) && isPrime(sumOfDigits(i))) {
            specialPrimes.push_back(i);
        }
    }

    // Ghi kết quả ra file PASSWORD.OUT
    ofstream output("PASSWORD.OUT");
    for (size_t i = 0; i < specialPrimes.size(); i++) {
        output << specialPrimes[i];
        if (i < specialPrimes.size() - 1) {
            output << " ";
        }
    }
    output << endl;
    output.close();

    return 0;
}
