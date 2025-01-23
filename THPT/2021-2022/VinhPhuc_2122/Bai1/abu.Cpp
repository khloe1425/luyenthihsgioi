#include <iostream>
#include <fstream>
#include <numeric> // for gcd

using namespace std;

// Hàm tính tổng ước của một số
long long sum_of_divisors(long long n) {
    long long sum = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum;
}

int main() {
    // Đọc dữ liệu từ file
    ifstream input("abu.inp");
    ofstream output("abu.out");

    long long x, y;
    input >> x >> y;

    // Tính tổng ước và abu cho hai số
    long long sum_x = sum_of_divisors(x);
    long long sum_y = sum_of_divisors(y);

    long long num_x = sum_x; // Tử số của abu(x)
    long long den_x = x;     // Mẫu số của abu(x)

    long long num_y = sum_y; // Tử số của abu(y)
    long long den_y = y;     // Mẫu số của abu(y)

    // Kiểm tra nếu tỷ lệ bằng nhau
    if (num_x * den_y == num_y * den_x) {
        // Tính phân số tối giản
        long long gcd_ab = gcd(num_x, den_x);
        output << num_x / gcd_ab << endl;
        output << den_x / gcd_ab << endl;
    } else {
        output << -1 << endl;
    }

    // Đóng file
    input.close();
    output.close();

    return 0;
}
