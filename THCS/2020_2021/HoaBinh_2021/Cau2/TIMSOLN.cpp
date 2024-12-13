#include <iostream>
#include <fstream>
using namespace std;

// Hàm tính USCLN (Ước số chung lớn nhất)
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Hàm tính tổng các chữ số của một số
long long sumOfDigits(long long x) {
    long long sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    ifstream inputFile("TIMSOLN.INP");
    ofstream outputFile("TIMSOLN.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    long long N;
    inputFile >> N;

    long long X = N;
    while (true) {
        long long Y = sumOfDigits(X);
        if (gcd(X, Y) > 1) {
            outputFile << X << endl;
            break;
        }
        X++;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
