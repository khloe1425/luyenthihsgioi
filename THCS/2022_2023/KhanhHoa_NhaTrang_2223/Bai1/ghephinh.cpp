#include <iostream>

using namespace std;

// Hàm tính số mảnh tối đa
int maxPieces(int n) {
    int x = n / 2;  // Số lần cắt theo chiều ngang
    int y = n - x;  // Số lần cắt theo chiều dọc
    return (x + 1) * (y + 1);  // Tính số mảnh giấy
}

int main() {
    int n;
    // Nhập số lần cắt
    cin >> n;
    // Tính và in ra số mảnh tối đa
    cout << maxPieces(n) << endl;
    return 0;
}
