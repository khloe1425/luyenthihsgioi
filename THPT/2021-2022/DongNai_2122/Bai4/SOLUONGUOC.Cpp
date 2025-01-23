#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Hàm tính số lượng ước của một số
int countDivisors(long long num) {
    int count = 0;
    for (long long i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            count += 2; // Đếm cả i và num / i
            if (i * i == num) { // Nếu i là căn bậc hai của num
                count--;
            }
        }
    }
    return count;
}

int main() {
    ifstream infile("SOLUONGUOC.INP");
    ofstream outfile("SOLUONGUOC.OUT");

    int n;
    infile >> n;

    vector<int> numbers(n);
    long long product = 1;

    // Đọc dữ liệu và tính tích
    for (int i = 0; i < n; i++) {
        infile >> numbers[i];
        product *= numbers[i];
    }

    // Tính số lượng ước của tích
    int divisors = countDivisors(product);

    // Ghi kết quả ra file
    outfile << divisors << endl;

    infile.close();
    outfile.close();

    return 0;
}
