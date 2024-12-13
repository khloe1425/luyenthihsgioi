#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Mở file input và output
    ifstream input("PTHUONG.INP");
    ofstream output("PTHUONG.OUT");

    long long n; // Số lượng kẹo
    input >> n;

    // Tính số cách chia kẹo
    long long result = n - 1;

    // Ghi kết quả ra file output
    output << result << endl;

    input.close();
    output.close();

    return 0;
}
