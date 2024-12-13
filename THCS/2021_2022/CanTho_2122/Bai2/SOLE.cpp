#include <iostream>
#include <fstream>
using namespace std;

// Hàm tính tổng các chữ số của một số
int sumOfDigits(long long x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

// Hàm kiểm tra tổng các chữ số có lẻ không
bool isOddSum(long long x) {
    return sumOfDigits(x) % 2 == 1;
}

// Đếm số lượng số có tổng chữ số lẻ trong đoạn [low, high]
long long countOddSumNumbers(long long low, long long high) {
    long long count = 0;
    for (long long i = low; i <= high; i++) {
        if (isOddSum(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    // Đọc dữ liệu từ file SOLE.INP
    ifstream input("SOLE.INP");
    ofstream output("SOLE.OUT");

    long long a, b;
    input >> a >> b;

    long long result;

    // Nếu đoạn nhỏ, duyệt từng số
    if (b - a <= 1000000) {
        result = countOddSumNumbers(a, b);
    } else {
        // Đoạn lớn, tối ưu hóa (sử dụng các đặc tính toán học nếu cần thiết)
        result = countOddSumNumbers(a, b); // Tạm thời vẫn duyệt (cần tối ưu hóa thêm)
    }

    // Ghi kết quả vào file SOLE.OUT
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
