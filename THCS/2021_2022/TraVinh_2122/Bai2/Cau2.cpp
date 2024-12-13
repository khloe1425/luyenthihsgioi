#include <iostream>
using namespace std;

// Hàm tính GCD (Ước chung lớn nhất)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 12; // Chiều dài của tấm bìa
    int b = 8;  // Chiều rộng của tấm bìa

    // Tính ước chung lớn nhất
    int maxSquareSide = gcd(a, b);

    // In kết quả
    cout << "Do dai lon nhat cua canh hinh vuong la: " << maxSquareSide << endl;

    return 0;
}
