#include <iostream>
using namespace std;

// Hàm tính ước số chung lớn nhất (GCD) bằng thuật toán Euclid
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

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
    int x = n; // Bắt đầu từ N
    while (true) {
        int y = sum_of_digits(x); // Tính tổng các chữ số của X
        // Kiểm tra điều kiện
        if (gcd(x, y) > 1) { 
            return x; // Trả về X nếu điều kiện thỏa mãn
        }
        x++; // Tăng X lên 1
    }
}

int main() {
    int n;
    cout << "Nhập số nguyên dương N: ";
    cin >> n; // Nhập số nguyên dương N

    // Gọi hàm tìm số nguyên dương nhỏ nhất thỏa mãn điều kiện
    int result = find_minimum_x(n);
    cout << "Số nguyên dương nhỏ nhất X là: " << result << endl;

    return 0;
}
