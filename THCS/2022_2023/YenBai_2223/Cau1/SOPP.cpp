#include <iostream>
#include <fstream>
using namespace std;

// Hàm kiểm tra xem một số có phải là số phong phú hay không
bool isAbundant(int n) {
    if (n <= 1) return false;
    int sum = 1; // Bắt đầu với 1 vì 1 là ước của mọi số lớn hơn 1

    // Tính tổng các ước số từ 2 đến căn bậc hai của n
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) { // Nếu không phải là số chính phương
                sum += n / i;
            }
        }
    }
    
    return sum > n; // Tổng các ước số phải lớn hơn n
}

// Hàm đếm số lượng số phong phú trong khoảng [a, b]
int countAbundantNumbers(int a, int b) {
    int count = 0;
    for (int i = a; i <= b; ++i) {
        if (isAbundant(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    // Đọc dữ liệu từ tệp
    ifstream infile("SOPP.INP");
    int a, b;
    infile >> a >> b;
    infile.close();

    // Tính số lượng số phong phú
    int result = countAbundantNumbers(a, b);

    // Ghi kết quả vào tệp
    ofstream outfile("SOPP.OUT");
    outfile << result << endl;
    outfile.close();

    return 0;
}
