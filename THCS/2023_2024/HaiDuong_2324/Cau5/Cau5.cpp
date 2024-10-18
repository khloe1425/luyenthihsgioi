#include <iostream>
using namespace std;

// Hàm tính tổng các chữ số của x
int sumOfDigits(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10; // Thêm chữ số cuối vào tổng
        x /= 10;       // Loại bỏ chữ số cuối
    }
    return sum;
}

// Hàm tìm số nghiệm nguyên dương của phương trình x + s(x) = n
int countSolutions(int n) {
    int count = 0;
    // Xét giá trị x từ n - 9 * số chữ số của n đến n
    for (int x = max(1, n - 9 * 10); x < n; x++) {
        if (x + sumOfDigits(x) == n) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    
    // Nhập dữ liệu từ bàn phím
    cout << "Nhập số nguyên dương n: ";
    cin >> n;

    int result = countSolutions(n); // Tính số nghiệm
    cout << result << endl;          // In ra kết quả
    return 0;
}
