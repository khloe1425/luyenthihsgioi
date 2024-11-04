#include <iostream>
#include <vector>

using namespace std;

// Hàm tính tổng các ước số của số n
int sumOfDivisors(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i; // i là ước
            if (i != n / i) {
                sum += n / i; // n / i cũng là ước
            }
        }
    }
    return sum;
}

// Hàm tìm số M lớn hơn N cùng tỉ ước
int findFriendlyNumber(int N) {
    int sumN = sumOfDivisors(N);
    double ratioN = static_cast<double>(sumN) / N;

    for (int M = N + 1; M <= 100000; ++M) {
        int sumM = sumOfDivisors(M);
        double ratioM = static_cast<double>(sumM) / M;

        if (ratioN == ratioM) {
            return M; // Trả về số M tìm được
        }
    }

    return -1; // Nếu không tìm thấy số nào thỏa mãn
}

int main() {
    int N;
    cout << "Nhap vao so N: ";
    cin >> N;

    int M = findFriendlyNumber(N);
    cout << M << endl;

    return 0;
}

