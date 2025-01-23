#include <bits/stdc++.h>
using namespace std;

const int MAX_PRIME = 1000000; // Giới hạn cho sàng nguyên tố
bool isPrime[MAX_PRIME + 5];
vector<int> primes;

// Sàng Eratosthenes để tìm các số nguyên tố <= sqrt(R)
void sieve() {
    fill(isPrime, isPrime + MAX_PRIME + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX_PRIME; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_PRIME; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

// Hàm đếm số ước của x
int countDivisors(long long x) {
    int cnt = 1; // Số ước
    for (long long p : primes) {
        if (p * p > x) break;
        int exp = 0;
        while (x % p == 0) {
            x /= p;
            exp++;
        }
        cnt *= (exp + 1); // Tính số ước
    }
    if (x > 1) cnt *= 2; // Nếu x còn lại là một số nguyên tố
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream fin("BAI4.INP");
    ofstream fout("BAI4.OUT");

    long long L, R;
    fin >> L >> R;

    sieve(); // Tiền xử lý sàng Eratosthenes

    int specialCount = 0;
    for (long long i = L; i <= R; i++) {
        int divisors = countDivisors(i);
        if (isPrime[divisors]) { // Kiểm tra số ước có phải là số nguyên tố không
            specialCount++;
        }
    }

    fout << specialCount << "\n";

    fin.close();
    fout.close();
    return 0;
}
