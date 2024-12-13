#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm đảo ngược số
int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    ifstream inputFile("BAI02.INP");
    ofstream outputFile("BAI02.OUT");

    if (!inputFile || !outputFile) {
        cerr << "Không thể mở file." << endl;
        return 1;
    }

    int P, Q;
    inputFile >> P >> Q;

    for (int N = P; N <= Q; N++) {
        int reversed = reverseNumber(N);
        if (isPrime(reversed)) {
            outputFile << N << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
