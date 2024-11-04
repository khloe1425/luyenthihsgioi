#include <iostream>
#include <fstream>

// Function to perform modular exponentiation
// It calculates (base^exp) % mod efficiently
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to find the smallest integer a such that a^a is divisible by N
int find_smallest_a(int N) {
    int a = 1;
    while (true) {
        if (mod_exp(a, a, N) == 0) {
            return a;
        }
        a++;
    }
}

int main() {
    std::ifstream infile("BAI03.INP");
    std::ofstream outfile("BAI03.OUT");

    if (!infile || !outfile) {
        std::cerr << "Error opening input or output file!" << std::endl;
        return 1;
    }

    int N;
    while (infile >> N) {
        int result = find_smallest_a(N);
        outfile << result << std::endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
