#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_X = 10000;

// Hàm sàng Eratosthenes để tìm các số nguyên tố
vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    ifstream input("COUNTPRIME.INP");
    ofstream output("COUNTPRIME.OUT");

    // Tìm các số nguyên tố nhỏ hơn hoặc bằng MAX_X
    vector<int> primes = generatePrimes(MAX_X);

    // Mảng dp để tính giá trị f(x)
    vector<int> dp(MAX_X + 1, 0);

    // Quy hoạch động
    for (int prime : primes) {
        for (int x = MAX_X; x >= prime; --x) {
            dp[x] = max(dp[x], dp[x - prime] + 1); // Sử dụng 1 lần
        }
        for (int x = MAX_X; x >= 2 * prime; --x) {
            dp[x] = max(dp[x], dp[x - 2 * prime] + 2); // Sử dụng 2 lần
        }
    }

    // Đọc dữ liệu từ file và xử lý
    int x;
    while (input >> x) {
        if (x <= MAX_X) {
            output << dp[x] << endl;
        } else {
            output << 0 << endl; // Trường hợp giá trị vượt giới hạn
        }
    }

    input.close();
    output.close();

    return 0;
}
