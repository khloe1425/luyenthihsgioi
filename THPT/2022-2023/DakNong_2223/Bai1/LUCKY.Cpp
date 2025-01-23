#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // Đọc dữ liệu từ file
    ifstream input("LUCKY.INP");
    ofstream output("LUCKY.OUT");
    int a, b;
    input >> a >> b;

    // Tìm số x nhỏ nhất
    int x = 1;
    while (!isPrime(a + b + x)) {
        x++;
    }

    // Ghi kết quả ra file
    output << x << endl;

    input.close();
    output.close();
    return 0;
}
