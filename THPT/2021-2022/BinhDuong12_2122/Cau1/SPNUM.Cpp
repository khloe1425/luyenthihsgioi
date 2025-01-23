#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int limit) {
    vector<int> primes;
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool isSpecialNumber(int n, const vector<int>& primes) {
    int originalSum = digitSum(n);
    int factorSum = 0;
    int temp = n;
    for (int prime : primes) {
        if (prime * prime > temp) break;
        while (temp % prime == 0) {
            factorSum += digitSum(prime);
            temp /= prime;
        }
    }
    if (temp > 1) {
        factorSum += digitSum(temp); // Remaining prime factor
    }
    return originalSum == factorSum;
}

int findSpecialNumber(int n) {
    vector<int> primes = sieve(1000000); // Limit for prime generation
    int current = n + 1;
    while (true) {
        if (isSpecialNumber(current, primes)) {
            return current;
        }
        ++current;
    }
}

int main() {
    ifstream infile("SPNUM.INP");
    ofstream outfile("SPNUM.OUT");

    int n;
    infile >> n;
    int result = findSpecialNumber(n);
    outfile << result << endl;

    infile.close();
    outfile.close();
    return 0;
}
