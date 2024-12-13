#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;

// Hàm sàng Eratosthenes để tìm các số nguyên tố
vector<int> sieve() {
    vector<int> primes;
    vector<bool> is_prime(MAX + 1, true);

    is_prime[0] = is_prime[1] = false; // 0 và 1 không phải số nguyên tố
    for (int i = 2; i <= MAX; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

// Hàm đếm số lượng ước nguyên tố của một số
int countPrimeFactors(int num, const vector<int>& primes) {
    int count = 0;
    for (int prime : primes) {
        if (prime * prime > num) break; // Tối ưu: chỉ xét đến sqrt(num)
        if (num % prime == 0) {
            count++;
            while (num % prime == 0) num /= prime; // Loại bỏ bội số
        }
    }
    if (num > 1) count++; // Nếu còn lại là một số nguyên tố
    return count;
}

int main() {
    // Mở file input và output
    freopen("UOCNGTO.INP", "r", stdin);
    freopen("UOCNGTO.OUT", "w", stdout);

    int A, B;
    cin >> A >> B;

    if (A <= 1 || B > MAX || A >= B) {
        cerr << "Giá trị A và B không hợp lệ!" << endl;
        return 1; // Trả về lỗi nếu đầu vào không hợp lệ
    }

    // Tìm danh sách các số nguyên tố
    vector<int> primes = sieve();

    int maxCount = 0;
    int resultK = A;

    // Duyệt qua các số trong khoảng [A, B]
    for (int i = A; i <= B; ++i) {
        int primeCount = countPrimeFactors(i, primes);
        if (primeCount > maxCount) {
            maxCount = primeCount;
            resultK = i;
        }
    }

    // Ghi kết quả ra file
    cout << resultK << " " << maxCount << endl;

    return 0;
}
