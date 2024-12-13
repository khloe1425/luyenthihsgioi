#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Function to count numbers <= N with exactly three divisors
int countNumbersWithThreeDivisors(int N) {
    int count = 0;
    for (int i = 2; i * i <= N; ++i) {
        if (isPrime(i)) {
            if (i * i <= N) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    // Reading input from BAUOC.INP
    std::ifstream inputFile("BAUOC.INP");
    int N;
    inputFile >> N;
    inputFile.close();

    // Calculating the result
    int result = countNumbersWithThreeDivisors(N);

    // Writing output to BAUOC.OUT
    std::ofstream outputFile("BAUOC.OUT");
    outputFile << result << std::endl;
    outputFile.close();

    return 0;
}
