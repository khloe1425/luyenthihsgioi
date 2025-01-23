#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

#define MAX_N 1000000

// Hàm tạo danh sách số nguyên tố lên đến MAX_N
void sieve(vector<bool>& is_prime) {
    is_prime[0] = is_prime[1] = false; // 0 và 1 không phải là số nguyên tố
    for (int i = 2; i <= sqrt(MAX_N); ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// Hàm tính tổng các số nguyên tố đầu tiên
long long sum_of_primes(int N, const vector<int>& primes) {
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += primes[i];
    }
    return sum;
}

int main() {
    // Đọc dữ liệu từ file
    ifstream input("nguyento.inp");
    ofstream output("nguyento.out");

    int T;
    input >> T;

    vector<bool> is_prime(MAX_N + 1, true);
    sieve(is_prime);

    // Tạo danh sách các số nguyên tố
    vector<int> primes;
    for (int i = 2; i <= MAX_N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    // Xử lý các test
    while (T--) {
        int N;
        input >> N;

        // Tính tổng các số nguyên tố đầu tiên
        long long result = sum_of_primes(N, primes);

        // Ghi kết quả vào file
        output << result << endl;
    }

    // Đóng file
    input.close();
    output.close();

    return 0;
}
