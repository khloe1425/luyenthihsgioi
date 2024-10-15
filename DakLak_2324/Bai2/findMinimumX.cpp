#include <iostream>
#include <numeric> // Để sử dụng hàm std::gcd
using namespace std;

// Hàm tính tổng các chữ số của số x
int sum_of_digits(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10; // Lấy chữ số cuối
        x /= 10;       // Bỏ chữ số cuối
    }
    return sum;
}

// Hàm tìm số nguyên dương nhỏ nhất X thỏa mãn yêu cầu
int find_minimum_x(int n) {
    int x = n;
    while (true) {
        int y = sum_of_digits(x);
        // Sử dụng std::gcd
        if (std::gcd(x, y) > 1) { 
            return x; // Trả về X nếu điều kiện thỏa mãn
        }
        x++; // Tăng X lên 1
    }
}

int main() {
    int n;
    cout << "Nhập số nguyên dương N: ";
    cin >> n; 

    int result = find_minimum_x(n);
    cout << result << endl;

    return 0;
}
