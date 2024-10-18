#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

// Hàm kiểm tra số đối xứng
bool is_palindrome(int n) {
    string s = to_string(n);
    int len = s.size();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1])
            return false;
    }
    return true;
}

// Hàm sàng Eratosthenes để tìm các số nguyên tố
vector<int> sieve_eratosthenes(int limit) {
    vector<int> primes;
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

// Hàm đếm số ước nguyên tố khác nhau
int count_prime_factors(int n, const vector<int>& primes) {
    set<int> prime_factors;
    for (int prime : primes) {
        if (prime * prime > n)
            break;
        if (n % prime == 0) {
            prime_factors.insert(prime);
            while (n % prime == 0)
                n /= prime;
        }
    }
    if (n > 1) {
        prime_factors.insert(n);
    }
    return prime_factors.size();
}

int main() {
    // Đọc dữ liệu từ tệp CAU3.INP
    ifstream infile("CAU3.INP");
    int a, b;
    infile >> a >> b;
    infile.close();

    // Sử dụng sàng Eratosthenes để tìm tất cả các số nguyên tố đến b
    vector<int> primes = sieve_eratosthenes(b);

    // Tính tổng các số đặc biệt
    long long special_sum = 0;

    for (int num = a; num <= b; num++) {
        if (is_palindrome(num)) {
            if (count_prime_factors(num, primes) >= 3) {
                special_sum += num;
            }
        }
    }

    // Ghi kết quả ra tệp CAU3.OUT
    ofstream outfile("CAU3.OUT");
    outfile << special_sum << endl;
    outfile.close();

    return 0;
}
