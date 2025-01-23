#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

// Hàm sàng Eratosthenes để tìm các số nguyên tố
vector<bool> sieve(int maxN) {
    vector<bool> isPrime(maxN + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= maxN; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

// Hàm tìm các ước nguyên tố duy nhất
set<int> findPrimeDivisors(int num, const vector<bool>& isPrime) {
    set<int> divisors;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0 && isPrime[i]) {
            divisors.insert(i);
            while (num % i == 0) num /= i;
        }
    }
    if (num > 1 && isPrime[num]) divisors.insert(num);
    return divisors;
}

int main() {
    ifstream input("SUPNUM.INP");
    ofstream output("SUPNUM.OUT");

    int n;
    input >> n;
    vector<int> a(n);
    int maxA = 0;
    for (int i = 0; i < n; ++i) {
        input >> a[i];
        maxA = max(maxA, a[i]);
    }

    // Tìm các số nguyên tố bằng sàng Eratosthenes
    vector<bool> isPrime = sieve(maxA);

    vector<int> specialNumbers;

    // Kiểm tra từng số trong dãy
    for (int num : a) {
        set<int> primeDivisors = findPrimeDivisors(num, isPrime);
        int sum = 0;
        for (int p : primeDivisors) {
            sum += p;
        }
        if (sum % 5 == 0) {
            specialNumbers.push_back(num);
        }
    }

    // Ghi kết quả
    if (specialNumbers.empty()) {
        output << -1 << endl;
    } else {
        for (size_t i = 0; i < specialNumbers.size(); ++i) {
            if (i > 0) output << " ";
            output << specialNumbers[i];
        }
        output << endl;
    }

    input.close();
    output.close();

    return 0;
}
