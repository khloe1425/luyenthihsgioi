#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream input("B1.INP");
    ofstream output("B1.OUT");

    long long x;
    input >> x;

    long long y = -1;

    // Tìm y nhỏ nhất
    for (long long k = 1; k * k <= x * 1000000; ++k) {
        long long square = k * k;
        if (square % x == 0) {
            y = square / x;
            break;
        }
    }

    output << y << endl;

    input.close();
    output.close();

    return 0;
}
