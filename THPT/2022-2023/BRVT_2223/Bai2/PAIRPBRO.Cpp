#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ifstream inputFile("PAIRPBRO.INP");
    ofstream outputFile("PAIRPBRO.OUT");

    int n, k;
    inputFile >> n >> k;

    vector<int> primes;
    // Tìm các số nguyên tố từ 1 đến n
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    int count = 0;
    // Đếm số cặp anh em
    for (size_t i = 0; i < primes.size(); i++) {
        for (size_t j = i + 1; j < primes.size(); j++) {
            if (primes[j] - primes[i] == k) {
                count++;
            }
        }
    }

    outputFile << count << endl;

    inputFile.close();
    outputFile.close();
    return 0;
}
