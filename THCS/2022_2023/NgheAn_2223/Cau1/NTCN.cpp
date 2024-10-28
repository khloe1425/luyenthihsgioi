#include <iostream>
#include <fstream>
using namespace std;

// Hàm tính phi(n)
long long euler_totient(long long n) {
    long long result = n; // Khởi tạo với n

    // Duyệt qua các số từ 2 đến sqrt(n)
    for (long long p = 2; p * p <= n; p++) {
        // Nếu p là ước số nguyên tố của n
        if (n % p == 0) {
            // Cập nhật result
            while (n % p == 0) {
                n /= p; // Loại bỏ ước số p khỏi n
            }
            result -= result / p; // Cập nhật phi(n)
        }
    }

    // Nếu n còn lớn hơn 1, thì n là một số nguyên tố
    if (n > 1) {
        result -= result / n; // Cập nhật phi(n) với n
    }

    return result;
}

int main() {
    ifstream input("NTCN.INP");
    ofstream output("NTCN.OUT");

    long long n;
    input >> n; // Đọc n

    // Tính số lượng số nguyên dương nhỏ hơn n và nguyên tố cùng nhau với n
    long long result = euler_totient(n);
    
    // Xuất kết quả ra tệp
    output << result << endl;

    // Đóng tệp
    input.close();
    output.close();

    return 0;
}
