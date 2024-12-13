#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input("PIN.INP");
    ofstream output("PIN.OUT");

    long long X, Y, N; // Số tiền cố định, phí vượt định mức, quãng đường
    input >> X >> Y >> N;

    long long totalCost;
    if (N <= 500) {
        totalCost = X; // Chỉ tính phí cố định
    } else {
        totalCost = X + (N - 500) * Y; // Thêm phí vượt định mức
    }

    output << totalCost << endl;

    input.close();
    output.close();

    return 0;
}
