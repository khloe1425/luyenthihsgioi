#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Hàm tính tổng từ 1 đến n
long long sumFrom1ToN(long long n) {
    return n * (n + 1) / 2;
}

int main() {
    ifstream input("BAI1.INP");
    ofstream output("BAI1.OUT");

    long long L, R;
    input >> L >> R;

    // Tổng toàn bộ từ L đến R
    long long totalSum = sumFrom1ToN(R) - sumFrom1ToN(L - 1);

    long long minDifference = LLONG_MAX;
    long long bestM = L;

    long long sumLtoM = 0;
    for (long long M = L; M < R; ++M) {
        // Cập nhật tổng từ L đến M
        sumLtoM += M;

        // Tổng từ M+1 đến R
        long long sumM1toR = totalSum - sumLtoM;

        // Tính chênh lệch
        long long difference = abs(sumLtoM - sumM1toR);

        // Kiểm tra và cập nhật kết quả tối ưu
        if (difference < minDifference) {
            minDifference = difference;
            bestM = M;
        }
    }

    output << bestM << endl;

    input.close();
    output.close();
    return 0;
}
