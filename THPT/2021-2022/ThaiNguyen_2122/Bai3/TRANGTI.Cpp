#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Hàm tính tổng các chữ số của một số
long long sumOfDigits(long long num) {
    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    ifstream input("TRANGTI.INP");
    ofstream output("TRANGTI.OUT");

    int Q; // Số lượng truy vấn
    input >> Q;

    while (Q--) {
        long long L, R;
        input >> L >> R;

        long long totalSum = 0;
        for (long long i = L; i <= R; i++) {
            totalSum += sumOfDigits(i);
        }

        output << totalSum << endl;
    }

    input.close();
    output.close();

    return 0;
}
