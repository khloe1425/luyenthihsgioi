#include <iostream>
using namespace std;

int main() {
    // Sử dụng giá trị cố định từ ví dụ
    int a = 122;
    int b = 123;

    int result = 0; // Kết quả của phép nhân

    // Hiển thị bảng tính như trong ví dụ
    cout << "Cột nhân đôi\tCột chia đôi" << endl;

    // Thực hiện thuật toán nhân Nga
    while (b > 0) {
        // In giá trị hiện tại của cột nhân đôi và cột chia đôi
        cout << a << "\t\t" << b << endl;

        // Nếu b là số lẻ, cộng giá trị của a vào kết quả
        if (b % 2 != 0) {
            result += a;
        }
        // Nhân đôi a và chia đôi b
        a *= 2;
        b /= 2;
    }

    // Hiển thị kết quả
    cout << "Tich = " << result << endl;

    return 0;
}
