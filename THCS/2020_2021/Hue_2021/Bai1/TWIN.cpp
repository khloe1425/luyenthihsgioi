// TWIN.CPP
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

// Sieve of Eratosthenes to find all primes <= n
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int main() {
    ifstream input("TWIN.INP");
    ofstream output("TWIN.OUT");

    if (!input || !output) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    int n;
    input >> n;

    // Find all primes up to n
    vector<bool> isPrime = sieve(n);

    // Find twin primes
    vector<pair<int, int>> twinPrimes;
    for (int i = 2; i <= n - 2; ++i) {
        if (isPrime[i] && isPrime[i + 2]) {
            twinPrimes.emplace_back(i, i + 2);
        }
    }

    // Output results
    for (size_t i = 0; i < twinPrimes.size(); ++i) {
        output << i + 1 << ": [" << twinPrimes[i].first << "," << twinPrimes[i].second << "]" << endl;
    }

    input.close();
    output.close();

    return 0;
}
